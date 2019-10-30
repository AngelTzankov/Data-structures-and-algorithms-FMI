#include <iostream>
using namespace std;

struct Stack
{
    int arr[1000];
    int size;
    Stack()
    {
        size = 0;
    }

    push(int x)
    {
        arr[size++] = x;
    }

    pop()
    {
        --size;
    }

    clear()
    {
        size = 0;
    }

    int top()
    {
        return arr[size-1];
    }
};
int main()
{
    Stack stack;
    int n, a;
    int g(int x)
    {
        return 1;
    };
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>a;
        stack.push(a);
    }
    for(int i=0;i<n;++i)
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;
    stack.clear();
    cout<<stack.size<<endl;
}
