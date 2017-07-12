#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes,bottles;
    printf("For how many minutes did you take shower today?\n");
    do
    {
        minutes = get_int();
    }
    while(minutes<0);
    bottles = minutes * 12;
    printf("thats %i bottles of water!\n",bottles);
}