#include <iostream>
#include <algorithm>
using namespace std;

bool covered[100000];
int n, k, arr[100000];

bool check(int towersCnt)
{
    for(int i=0; i<n; ++i)
    {
        if(!covered[arr[i]])
        {
            int j = i;
            --towersCnt;
            while(arr[j] <= arr[i] + 2*k)
            {
                covered[j] = 1;
                ++j;
            }
            --j;
            int l = j+1;
            while(arr[l] <= arr[j] + 2*k)
            {
                covered[l] = 1;
                ++j;
            }
        }
    }
    return towersCnt >= 0;
}

int getSmallestNumberOfTowersNeeded()
{
    int left = 0, right = 100000, result;;
    while(left <= right)
    {
        int mid = (left+right)/2;
        if(check(mid))
        {
            result = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return result;
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }
    int ans = 0;
    sort(arr, arr+n);
}
