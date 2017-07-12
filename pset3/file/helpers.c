/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdlib.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int mid = n/2;
    int low = 0,high = n-1;
    sort(values,n);
    while(low<=high)
    {
        if(values[mid]==value)
            return true;
        else if(value<values[mid])
            high = (mid-1);
        else if(value>values[mid])
            low = (mid+1);
        mid = low + (high-low)/2;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int i,temp;
    for(i=0;i<n;i++)
    {
        if(values[i] > values[i+1])
        {
            temp = values[i];
            values[i] = values[i+1];
            values[i+1] = temp;
        }
    }
}
