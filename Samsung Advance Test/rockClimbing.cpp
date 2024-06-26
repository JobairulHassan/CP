#include <iostream>
#include <vector>
using namespace std;

int n, m,flag;
vector<vector<int>> mat;
vector<vector<int>> visited;
void solve(int i, int j, int l)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    if(visited[i][j]==1)
        return;
    visited[i][j]=1;
    if(mat[i][j]==3)
    {
        flag = 1;
        return;
    }
    if(j+1<m && visited[i][j+1]==0 && (mat[i][j+1]==1 || mat[i][j+1]==3))
        solve(i, j+1, l);
    if(j-1>=0 && visited[i][j-1]==0 && (mat[i][j-1]==1 || mat[i][j-1]==3))
        solve(i, j-1, l);

    for(int h =1; h<=l; h++)
        if(h<=l && i-h>=0 && visited[i-h][j]==0 && (mat[i-h][j]==1 || mat[i-h][j]==3))
            solve(i-h, j, l);
    for(int h =1; h<=l; h++)
        if(h<=l && i+h<n && visited[i+h][j]==0 && (mat[i+h][j]==1 || mat[i+h][j]==3))
            solve(i+h, j, l);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        mat.push_back(tmp);
    }
    for (int l = 0; l < n; l++)
    {
        visited.clear();
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < m; j++)
            {
                tmp.push_back(0);
            }
            visited.push_back(tmp);
        }
        flag =0;
        solve(n - 1, 0, l);
        if(flag)
        {
            cout<<l<<endl;
            break;
        }
    }
    return 0;
}