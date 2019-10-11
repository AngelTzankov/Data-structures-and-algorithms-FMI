#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int pow(int x, int pow)
{
    int res = 1;
    for(int i=0;i<pow;++i)
    {
        res*=x;
    }
    return res;
}

// Complete the powerSum function below.
void generatePowerSum(int x, int n, int last)
{
    if(x < 0)
    {
        return;
    }
    if(x == 0)
    {
        ++ans;
        return;
    }
    for(int i=last+1; pow(i, n) <= x; ++i)
    {
        generatePowerSum(x-pow(i, n), n, i);
    }
}

int main()
{
    int x, n;
    cin>>x>>n;
    generatePowerSum(x, n, 0);
    cout<<ans<<endl;
}

