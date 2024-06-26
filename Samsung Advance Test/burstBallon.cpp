#include<bits/stdc++.h>
using namespace std;
int n, ans=0;
vector<int>v;
vector<int>visited;
void solve(int cnt, int res)
{
    if(cnt == n)
    {
        ans = max(ans, res);
        return;
    }
    int tmp_res = res;

    for(int i =0; i<n;i++)
    {
        int l_flag=0, r_flag = 0,l_val =1, r_val=1;
        if(!visited[i])
        {
            visited[i] = 1;
            for(int j = i-1; j>= 0; j--)
            {
                if(!visited[j])
                {
                    l_flag = 1;
                    l_val = v[j];
                    break;
                }
            }
            for(int j = i+1; j<n; j++)
            {
                if(!visited[j])
                {
                    r_flag = 1;
                    r_val = v[j];
                    break;
                }
            }

            if(l_flag == 1 && r_flag == 1)
                res += l_val * r_val;
            else if(l_flag== 0 && r_flag ==1)
                res += r_val;
            else if(l_flag== 1 && r_flag == 0)
                res += l_val;
            else
                res += v[i];
            solve(cnt+1, res);
            res = tmp_res;
            visited[i] =0;

        }
    }

}
int main()
{

    cin>>n;
    v.resize(n);
    visited.assign(n,0);
    for(int i = 0; i<n ; i++)
    {
        cin>>v[i];
    }
    solve(0, 0);
    cout<<ans<<endl;
    return 0;
}