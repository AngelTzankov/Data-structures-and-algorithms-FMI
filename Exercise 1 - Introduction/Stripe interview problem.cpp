#include <cstdio>
#include <iostream>
using namespace std;
/*
This problem was asked by Stripe.

PROBLEM STATEMENT
Given an array of integers, find the first missing
positive integer in linear time and constant space.
In other words, find the lowest positive integer that
does not exist in the array. The array can contain
duplicates and negative numbers as well.
*/

int arr[1000000];


/*
SOLUTION ANALYSIS
The idea behind the solution is as follows:
Rearrange the array so that every positive number
x is located in the element of the array with index
x-1 and all the numbers in the initial state of the array
are also present after the rearrangement. If we perform
such manipulation in linear time the answer to the problem
will be the 1 + the first index in the array that does not
contains a number not equal to the index + 1.
*/
int getAnswer(int arrLen, int* arr)
{
    for(int i=0; i<arrLen; ++i)
    {
        if(arr[i] > 0 && arr[i] <= arrLen && arr[i] != i+1)
        {
            swap(arr[i], arr[arr[i]-1]);
            /// here the decrementation if i is needed because the value we swap arr[i] with may also need to change position. An example of this is the array [3, 4, -1, 1]
            --i;
        }
    }
    int ans = arrLen+1;
    for(int i=0; i<arrLen; ++i)
    {
        if(arr[i] != i+1)
        {
            ans = i+1;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &arr[i]);

    }
    cout<<getAnswer(n, arr)<<endl;
}
