#include <bits/stdc++.h>
using namespace std;
/*
Problem statement: https://www.hackerrank.com/challenges/reduced-string/problem?h_r=internal-search
*/

int n, m, results[200000], aliceScores[200000], pos[200000];


/*
Solution
First calculate the position of every
result. After we have the results, we
use binary search for every score of Alice to
find which position it would take.

!!!Note that binary search has not yet been taken
in lectures so it will not be needed for any homework
or test before it is talked about in lectures.

Time complexity - O(n+m*log2(n))
Space complexity - O(n+m), where n is the size of
the results array and m is the size of the array with
the scores of Alice.
*/
int getPlace(int x)
{
    int l = 0, r = n -1;
    while(l<r)
    {
        if(results[(l+r)/2] <= x)
            r = (l+r)/2;
        else
            l = (l+r)/2+1;
    }
    if(results[r] <= x)
        return pos[r];
    else
        return pos[r]+1;
}

void calculatePositions()
{
    int currentPosition = 1;
    pos[0] = 1;
    for(int i=1;i<n;++i)
    {
        if(results[i] == results[i-1])
        {
            pos[i] = currentPosition;
        }
        else
        {
            pos[i] = ++currentPosition;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        scanf("%d", &results[i]);
    }
    calculatePositions();
    scanf("%d", &m);
    for(int i=0;i<m;++i)
    {
        scanf("%d", &aliceScores[i]);
        printf("%d\n", getPlace(aliceScores[i]));
    }
}
