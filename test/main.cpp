#include<iostream>
using namespace std;
string m[2]={"NO","YES"};

int judge(string str)
{
    int array[4]={};
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='P') array[0]++;
        else if(str[i]=='A') array[1]++;
        else if(str[i]=='T') array[2]++;
        else array[3]++;
    }
    if(array[3]!=0||array[0]!=1||array[2]!=1||array[1]==0) return 0;
    int p,t;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='P')
        {
            p = i;
            break;
        }
    }
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='T')
        {
            t=i;
            break;
        }
    }
    if(p*(t-p-1)==str.length()-t-1&&t-p>1) return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        cout << m[judge(s)] << endl;
    }
}