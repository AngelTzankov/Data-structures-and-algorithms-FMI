#include<iostream>
#include <cstdio>
#include<algorithm>
using namespace std;

int n;
long long arr[1000];

int numberOfOccurrences(int x)
{
    int left = 0, right = n-1, leftMostOccurrenceIndex = -1;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(x == arr[mid])
        {
            leftMostOccurrenceIndex = mid;
            right = mid - 1;
        }
        else if(x < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(leftMostOccurrenceIndex = -1)
    {
        return 0;
    }
    cout<<arr[leftMostOccurrenceIndex]<<" "<<x<<endl;
    int result = 0;
    while(leftMostOccurrenceIndex < n && arr[leftMostOccurrenceIndex++] == x)
    {
        result++;
    }
    return result;
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        scanf("%d", &arr[i]);
    }
    int k, ans = 0;
    scanf("%d", &k);
    sort(arr, arr+n);
    for(int i=0;i<n - 1;++i)
    {
        ans += numberOfOccurrences(k+arr[i]);
    }
    cout<<ans<<endl;
}
