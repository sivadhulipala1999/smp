#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n,i,j,k;
    do
    {
        printf("Height: ");
        n = get_int();
    }while(n<0);
    for(i=2;i<n+2;i++)
    {
        for(j=n-i+2;j>0;j--)
            printf(" ");
        for(k=0;k<i;k++)
            printf("#");
        printf("\n");
    }
}