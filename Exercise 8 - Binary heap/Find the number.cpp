#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    priority_queue<int> q;
    int num;
    char command = ' ';
    while(command != 'Q')
    {
        scanf("%c", &command);
        if(command == 'A')
        {
            scanf("%d", &num);
            q.push(num);
        }
        else if(command == 'L')
        {
            if(q.size() > 0)
                printf("%d\n", q.top());
            else
                printf("Not available\n");
        }
        else if(command == 'R')
        {
            if(q.size() > 0)
            {
                printf("%d\n", q.top());
                q.pop();
            }
            else
                printf("Not available\n");
        }
    }
}
/*
A 18467
L
A 19169
L
R
R
R
A 24464
L
R
A 16827
A 491
L
A 4827
L
R
R
A 153
A 12382
L
R
Q
*/
