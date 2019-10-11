#include <bits/stdc++.h>

using namespace std;
int n, m, res[200000], alice[200000], pos[200000];

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

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>res[i];
    }
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
    cin>>m;
    for(int i=0;i<m;++i)
    {
        cin>>alice[i];
        cout<<getPlace(alice[i])<<endl;
    }
}
