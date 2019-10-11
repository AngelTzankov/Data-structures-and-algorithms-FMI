#include <iostream>

using namespace std;

int letterUsage[26];
int main()
{

    ios::sync_with_stdio(false);

    string str;
    cin>>str;
    for(int i=0; i<str.length(); ++i)
    {
        letterUsage[str[i]-'a']++;
    }

    int oddCountLetters = 0;
    for(int i=0; i<26; ++i)
    {
        if(letterUsage[i] % 2 == 1)
        {
            oddCountLetters++;
        }
    }

    if(oddCountLetters <= 1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
