#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>p;
vector<int> visited;
int n, home_x, home_y, ofc_x, ofc_y, opt_route;

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}

void solve(int cur, int cost, int node_left)
{
    if(node_left == 1)

    {
        if(cost+dist(p[cur].first, p[cur].second, home_x, home_y) < opt_route)
        {
            opt_route = cost+dist(p[cur].first, p[cur].second, home_x, home_y);
        }
        return;
    }
    visited[cur] = 1;
    for(int i = 0; i< n; i++)
    {
        if(visited[i] == 0)
            solve(i,cost+dist(p[cur].first, p[cur].second, p[i].first, p[i].second),node_left-1);
    }
    visited[cur] = 0;
}
int main()
{
    int t=1;
    while(t<=10)
    {
        cin>>n>>ofc_x>>ofc_y>>home_x>>home_y;
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            p.push_back(make_pair(x,y));
        }
        visited.assign(n,0);
        opt_route = INT_MAX;
        for(int i =0; i<n; i++)
        {
            solve(i,dist(ofc_x, ofc_y, p[i].first, p[i].second),n);
        }
        cout<<"# "<<t<<" "<< opt_route<<endl;
        visited.clear();
        p.clear();
        ++t;
    }
    return 0;
}