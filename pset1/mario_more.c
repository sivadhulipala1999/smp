#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int height,i,j,k;
   do
   {
        printf("Height: ");
        height = get_int();
   }while(height<0);
   for(i=0;i<height;i++)
   {
       for(j = height-i ; j > 0 ; j--)
        printf(" ");
       for(k = 0 ; k <= i ; k++)
        printf("#");
       printf(" ");
       for(k = 0 ; k <= i ; k++)
        printf("#");
        printf("\n");
   }
}