#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int arr[4]={1,5,10,25};
    float money;
    int i,count=0;
    do
    {
        printf("O hai! how much change is owed?\n");
        money = get_float();
    }while(money<0);
    if(money<1)
        money = money * 100;
    for(i=3;i>=0;i--)
    {
        if(money>0)
        {
            if(money>=arr[i])
                money = money-arr[i];
            count++;
        }
        else
            break;
    }
    printf("%i\n",count);
}