#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
/*
Problem statement: https://www.hackerrank.com/challenges/plus-minus/problem?h_r=internal-search
*/

int main()
{
    int n;
    int arr[100];
    int positiveCnt = 0, zeroCnt = 0, negativeCnt = 0;
    ios::sync_with_stdio(false);
    cin>>n;
    // scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
        // scanf("%d", &arr[i]);
        if( arr[i] > 0 )
        {
            positiveCnt++;
        }
        else if( arr[i] == 0 )
        {
            zeroCnt++;
        }
        else
        {
            negativeCnt++;
        }
    }
    cout<<fixed;
    cout<<setprecision(6)<<(double)positiveCnt/(double)n<<endl;
    cout<<setprecision(6)<<(double)negativeCnt/(double)n<<endl;
    cout<<setprecision(6)<<(double)zeroCnt/(double)n<<endl;
    // printf("%.6f\n", (double)positiveCnt/(double)n);
    // printf("%.6f\n", (double)negativeCnt/(double)n);
    // printf("%.6f\n", (double)zeroCnt/(double)n);
}
