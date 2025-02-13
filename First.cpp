#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    map<char, int>m;
    for(char i='A'; i<='Z'; i++)
        m[i]=1;
    vector<char>v;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='=' && m[s[i+1]]==0)
            v.push_back(s[i+1]);
        if(s[i]=='/' && m[s[i+1]]==0)
            v.push_back(s[i+1]);

    }
    cout<<"First Positions: { ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
        cout<<'}'<<endl;
    return 0;
}

