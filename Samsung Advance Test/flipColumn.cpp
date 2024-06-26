#include<bits/stdc++.h>
using namespace std;

int n, m, mat[15][15], ans = 0;
void flip(int j)
{
    for(int i =0; i<n; i++)
    {
        if(mat[i][j])
            mat[i][j] = 0;
        else
            mat[i][j] = 1;
    }
}
void solve(int k)
{
    if(k == 0)
    {
        int row = 0;
        for(int i = 0; i<n; i++)
        {
            int flag = 1;
            for(int j = 0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ++row;
            }
        }
        ans = max(row, ans);
        return;
    }

    for(int x =0; x<m; x++)
    {
        flip(x);
        solve(k-1);
        flip(x);
    }
}
int main()
{
    int k;
    cin>>n>>m>>k;
    for(int i= 0; i<n;i++)
    {
        for(int j= 0; j<m; j++)
        {
            cin>>mat[i][j];
        }
    }
    solve(k);
    cout<<ans<<endl;
    return 0;
}