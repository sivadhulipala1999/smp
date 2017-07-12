#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,string argv[])
{
    if(argc==2)
    {
        int k,i;
        k = atoi(argv[1]);
        printf("plaintext:");
        string plain = get_string();
        int len = strlen(plain);
        for(i=0;i<len;i++)
        {
            if(isalpha(plain[i]))
            {
                if(islower(plain[i]))
                {
                    plain[i] = (((plain[i]+k-'a')%26)+'a');
                }
                if(isupper(plain[i]))
                {
                    plain[i] = (((plain[i]+k-'A')%26)+'A');
                }
            }
        }
        printf("ciphertext:%s\n",plain);
    }
}