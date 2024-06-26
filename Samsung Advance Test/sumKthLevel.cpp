#include<bits/stdc++.h>
using namespace std;
string s;
int k;

int main()
{
    cin>>k;
    cin>>s;
    int cnt =-1, ans =0;
    for(int i =0; i<s.size(); i++)
    {
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        else if(cnt == k)
        {
            int x= s[i] - '0';
            i++;
            while(s[i] >48 && s[i]<57)
            {
                int d = s[i]-'0';
                x = x*10+d;
                i++;
            }
            i--;
            ans+=x;
        }
    }
    cout<<ans<<endl;
    return 0;
}