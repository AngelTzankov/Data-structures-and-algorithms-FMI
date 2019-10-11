#include <iostream>
using namespace std;

int main()
{
    string str;
    string ansStr = "";
    cin>>str;
    int ansStrLen = 0;
    int n = str.length();
    ansStr.resize(n);
    for(int i=0;i<n-1;++i)
    {
        ansStr[ansStrLen] = str[i];
        if(ansStrLen != 0)
        {
            if(ansStr[ansStrLen-1] == ansStr[ansStrLen])
                ansStrLen -= 2;
        }
        ansStrLen++;
    }
    if(ansStr.length() > 0)
    {
        cout<<ansStr.substr(0, ansStrLen)<<endl;
    }
    else
    {
        cout<<"Empty String"<<endl;
    }
}
