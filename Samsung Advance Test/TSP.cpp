#include<bits/stdc++.h>
using namespace std;

int n, opt_cost;
vector<vector<int>>mat;
vector<int>visited;

void explore(int cur, int cnt, int cost)
{
    if(cnt == n)
    {
        opt_cost = min(opt_cost, cost+mat[cur][0]);
        return;
    }
    for(int i =0; i<n; i++)
    {
        if(visited[i] ==0)
        {
            visited[i] = 1;
            explore(i, cnt+1, cost+mat[cur][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    int t, x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0; i<n; i++)
        {
            vector<int>tmp;
            for(int j =0; j<n; j++)
            {
                cin>>x;
                tmp.push_back(x);
            }
            mat.push_back(tmp);
        }
        visited.assign(n, 0);
        visited[0] = 1;
        opt_cost = INT_MAX;
        explore(0, 1, 0);   //current node, count, cost
        cout<<opt_cost<<endl;
        visited.clear();
        mat.clear();

    }
    return 0;
}