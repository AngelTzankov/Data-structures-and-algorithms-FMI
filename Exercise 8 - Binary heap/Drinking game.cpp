#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

struct CustomCompare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};


int main()
{
    priority_queue<int, vector<int>, CustomCompare> q;
    int n, k;
    int command, value, queueNumber;
    cin>>k>>n;
    for(int i=0;i<n;++i)
    {
        scanf("%d", &command);
        if(command == 1)
        {
            scanf("%d", &queueNumber);
            scanf("%d", &value);
            q.push(value);
        }
        else
        {
            printf("%d\n", q.top());
            q.pop();
        }
    }
}
