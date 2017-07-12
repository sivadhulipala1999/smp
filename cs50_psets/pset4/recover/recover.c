#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc,string argv[])
{
    if(argc==1)
    {
        fprintf(stderr,"Usage : ./recover name\n");
        return 1;
    }
    string file = argv[1];
    FILE *fptr = fopen(file,"r");
    FILE *optr = NULL;
    if(fptr==NULL)
    {
        fprintf(stderr,"Sorry! the file can't be opened for reading\n");
        return 2;
    }
    
    uint8_t buffer[512];
    int file_no = 000;
    char file_name[8];
    for(int i=0;i<8;i++)
        file_name[i] = '\0';
    while( fread(buffer,512,1,fptr)==1)
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0)==0xe0)
        {
            if(optr!=NULL)
            {
                fclose(optr);
                optr = NULL; 
            }
            else
            {
                sprintf(file_name,"%03d.jpg",file_no);//creating a name for the file
                optr = fopen(file_name,"w");
                if(optr==NULL)
                    printf("file %s not found\n",file_name);//incase the file is not found
                else
                {
                    fwrite(buffer,512,1,optr);//write the data to the file
                    file_no++;//increment the count
                }
            }
        }
        else
        {
            if(optr!=NULL)
                fwrite(buffer,512,1,optr);//the jpg file may not have ended 
        }
    }
    return 0;
}