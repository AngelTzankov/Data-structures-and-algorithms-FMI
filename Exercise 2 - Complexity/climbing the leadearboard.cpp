#include <bits/stdc++.h>
using namespace std;

int n, m, res[200000], aliceScores[200000], pos[200000];

int getPlace(int x)
{
    int l = 0, r = n -1;
    while(l<r)
    {
        if(res[(l+r)/2] <= x)
            r = (l+r)/2;
        else
            l = (l+r)/2+1;
    }
    if(res[r] <= x)
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
        if(res[i] == res[i-1])
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
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    for(int i=0;i<m;++i)
    {
        scanf("%d", &aliceScores[i]);
        printf("%d\n", getPlace(aliceScores[i]));
    }
}
