#include <iostream>
using namespace std;
/*
Problem statement: https://www.hackerrank.com/challenges/reduced-string/problem?h_r=internal-search
*/

/*
Solution idea: Iterate the string adding every letter
to the answer string and if the latter has two consecutive
letters at any point remove the last two letters and continue.

This problem can also be solved very easily with a stack.
*/
int main()
{
    string str, ansStr;
    ios::sync_with_stdio(false);
    cin>>str;

    int ansStrLen = 0, inputStrLen = str.length();
    ansStr.resize(inputStrLen);

    for(int i=0;i<inputStrLen;++i)
    {
        ansStr[ansStrLen] = str[i];
        if(ansStrLen != 0)
        {
            if(ansStr[ansStrLen-1] == ansStr[ansStrLen])
                ansStrLen -= 2;
        }
        ansStrLen++;
    }
    if(ansStrLen > 0)
    {
        cout<<ansStr.substr(0, ansStrLen)<<endl;
    }
    else
    {
        cout<<"Empty String"<<endl;
    }
}
