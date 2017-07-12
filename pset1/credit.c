#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long credit;
    int i=1,rem,sum=0;
    printf("Number: ");
    credit = get_long_long();
    while(credit>10)
    {
        rem = credit%10;
        if(i%2==0)
        {
            if(rem>=5)
            {
                rem = rem-5;
                rem = rem * 2;
                sum = sum + 1 + rem;
            }
            else
                sum = sum + rem * 2; 
        }
        else
            sum = sum + rem;
        i++;
        credit = credit/10;
    }
    if(i%2==0)
    {
        if(credit>=5)
        {
            credit-=5;
            credit*=2;
            sum += credit+1;
        }
        else
            sum += 2 * credit;
    }
    else
        sum = sum + credit;
    if(sum%10==0)
    {
        switch(credit)
        {
            case 3: printf("AMEX\n");
                    break;
            case 4: printf("VISA\n");
                    break;
            case 5: printf("MASTERCARD\n");
                    break;
            default:
                printf("INVALID\n");
        }
    }
    else
        printf("INVALID\n");
}