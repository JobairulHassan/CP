#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> parent, dist, vis, tmp;
vector<vector<int>> adj;
int ans = 9999, n, m;

void bfs(int x)
{
    vis.assign(n + 1, 0);
    dist.assign(n + 1, 9999);
    parent.assign(n + 1, -1);

    vis[x] = 1;
    dist[x] = 0;
    queue<int> q;
    q.push(x);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto i : adj[top])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                dist[i] = dist[top] + 1;
                parent[i] = top;
                q.push(i);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        for (auto j : adj[i])
        {
            if (j == x && ans > dist[i] + 1 && vis[i])
            {
                ans = dist[i] + 1;
                tmp.clear();
                tmp.push_back(x);
                for (int k = i; k != x; k = parent[k])
                    tmp.push_back(k);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }

    sort(tmp.begin(), tmp.end());
    for (auto x : tmp)
        cout << x << " ";
    cout << endl;
    return 0;
}