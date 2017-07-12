#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    int i=0;
    if(name != NULL)
    {
        while(name[i]!='\0')
        {
            if(!(isalpha(name[i])))
            {
                i++;
            }
            else
            {
                printf("%c",toupper(name[i]));
                while(isalpha(name[i]))
                    i++;
            }
        }
    }
    printf("\n");
}