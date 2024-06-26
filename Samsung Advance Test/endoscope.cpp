#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
vector<vector<int>> visited;
vector<vector<int>> mat;

void graph(int r, int c, int l)
{

    if (l == 0)
        return;
    visited[r][c] =1;
    if (mat[r][c] == 1)
    {
        if(r!=0 && (mat[r-1][c] == 2 || mat[r-1][c] ==5 || mat[r-1][c] ==6 || mat[r-1][c] ==1))  //up
            graph(r-1, c, l-1);
        if((r!=n-1) && (mat[r+1][c] ==2 || mat[r+1][c] ==4 || mat[r+1][c] ==7 || mat[r+1][c] ==1)) //down
            graph(r+1, c, l-1);

        if((c!=0)&& (mat[r][c-1] ==3 || mat[r][c-1] ==4 || mat[r][c-1] ==5 || mat[r][c-1] ==1))     //left
            graph(r, c-1, l-1);
        if((c!=m-1) && (mat[r][c+1] ==3 || mat[r][c+1] ==6 || mat[r][c+1] ==7 || mat[r][c+1] ==1))   //right
            graph(r, c+1, l-1);

    }
    else if (mat[r][c] == 2)
    {
        if(r!=0 && (mat[r-1][c] == 2 || mat[r-1][c] ==5 || mat[r-1][c] ==6 || mat[r-1][c] ==1))  //up
            graph(r-1, c, l-1);
        if((r!=n-1) && (mat[r+1][c] ==2 || mat[r+1][c] ==4 || mat[r+1][c] ==7 || mat[r+1][c] ==1)) //down
            graph(r+1, c, l-1);
    }
    else if (mat[r][c] == 3)
    {
        if((c!=0)&& (mat[r][c-1] ==3 || mat[r][c-1] ==4 || mat[r][c-1] ==5 || mat[r][c-1] ==1))     //left
            graph(r, c-1, l-1);
        if((c!=m-1) && (mat[r][c+1] ==3 || mat[r][c+1] ==6 || mat[r][c+1] ==7 || mat[r][c+1] ==1))   //right
            graph(r, c+1, l-1);
    }
    else if (mat[r][c] == 4)
    {
        if(r!=0 && (mat[r-1][c] == 2 || mat[r-1][c] ==5 || mat[r-1][c] ==6 || mat[r-1][c] ==1))  //up
            graph(r-1, c, l-1);
        if((c!=m-1) && (mat[r][c+1] ==3 || mat[r][c+1] ==6 || mat[r][c+1] ==7 || mat[r][c+1] ==1))   //right
            graph(r, c+1, l-1);
    }
    else if (mat[r][c] == 5)
    {
        if((r!=n-1) && (mat[r+1][c] ==2 || mat[r+1][c] ==4 || mat[r+1][c] ==7 || mat[r+1][c] ==1)) //down
            graph(r+1, c, l-1);
        if((c!=m-1) && (mat[r][c+1] ==3 || mat[r][c+1] ==6 || mat[r][c+1] ==7 || mat[r][c+1] ==1))   //right
            graph(r, c+1, l-1);

    }
    else if (mat[r][c] == 6)
    {
        if((r!=n-1) && (mat[r+1][c] ==2 || mat[r+1][c] ==4 || mat[r+1][c] ==7 || mat[r+1][c] ==1)) //down
            graph(r+1, c, l-1);
        if((c!=0)&& (mat[r][c-1] ==3 || mat[r][c-1] ==4 || mat[r][c-1] ==5 || mat[r][c-1] ==1))     //left
            graph(r, c-1, l-1);
    }
    else if (mat[r][c] == 7)
    {
        if(r!=0 && (mat[r-1][c] == 2 || mat[r-1][c] ==5 || mat[r-1][c] ==6 || mat[r-1][c] ==1))  //up
            graph(r-1, c, l-1);
        if((c!=0)&& (mat[r][c-1] ==3 || mat[r][c-1] ==4 || mat[r][c-1] ==5 || mat[r][c-1] ==1))     //left
            graph(r, c-1, l-1);
    }
}
int main()
{
    int t, r, c, l, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> r >> c >> l;
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                cin >> x;
                tmp.push_back(x);
            }
            mat.push_back(tmp);
        }

        visited.assign(n, vector<int>(m, 0));
        ans = 0;
        graph(r, c, l);
        for(int i = 0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(visited[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        mat.clear();
        visited.clear();
    }
    return 0;
}
