#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc,string argv[])
{
    if(argc>1)
    {
        char key[1000] = {'\0'};
        int i=1;
        while(i<argc)
        {
            strcat(key,argv[i]);
            i++;
        }
        int len = strlen(key);
        i=0;
        int j=0;
        printf("plaintext:");
        string answer = get_string();
        while(answer[i]!='\0')
        {
            if(isalpha(key[j%len]))
            {
                if(isupper(key[j%len]))
                {
                    if(islower(answer[i]))
                        answer[i] = (answer[i]+(key[j%len] - 'A')-'a')%26 + 'a';
                    else if(isupper(answer[i]))
                        answer[i] = (answer[i]+(key[j%len]-'A')-'A')%26 + 'A';
                    j++;
                }
                else if(islower(key[j%len]))
                {
                    if(isupper(answer[i]))
                        answer[i] = (answer[i]+(key[j%len]-'a')-'A')%26 + 'A';
                    else if(islower(answer[i]))
                        answer[i] = (answer[i]+(key[j%len]-'a')-'a')%26 + 'a';
                    j++;
                }
            }
            i++;
        }
        printf("%s",answer);
    }
    else
        exit(1);
}