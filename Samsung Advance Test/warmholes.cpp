#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define inf 9999;
int n;

struct vartex
{
    int num;
    int x;
    int y;
    int cost;
};
vector<vartex> node;
vector<vector<int>> graph;
int dij()
{
    int c=0;
    queue<vartex> q;
    q.push(node[0]);
    while (!q.empty())
    {
        vartex var = q.front();
        q.pop();
        for (int i = 0; i < 2 * n + 2; i++)
        {
            int nxtnode = i;
            int adjwt = graph[i][var.num];
            if (var.cost + adjwt < node[nxtnode].cost)
            {
                node[nxtnode].cost = var.cost + adjwt;
                q.push(node[nxtnode]);
            }
        }
    }
    return node[1].cost;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        node.resize(2 * n + 2);
        graph.assign(2 * n + 2, vector<int>(2 * n + 2, -1));

        cin >> node[0].x >> node[0].y;
        node[0].cost = 0;
        node[0].num = 0;
        cin >> node[1].x >> node[1].y;
        node[1].cost = inf;
        node[1].num = 1;
        for (int i = 2; i < 2 * n + 2; i = i + 2)
        {
            int cst;
            cin >> node[i].x >> node[i].y >> node[i + 1].x >> node[i + 1].y >> cst;
            node[i].cost = inf;
            node[i].num = i;
            node[i + 1].cost = inf;
            node[i + 1].num = i + 1;
            graph[i][i + 1] = cst;
            graph[i + 1][i] = cst;
        }

        for (int i = 0; i < 2 * n + 2; i++)
        {
            for (int j = 0; j < 2 * n + 2; j++)
            {
                if (graph[i][j] != -1)
                    continue;
                graph[i][j] = abs(node[i].x - node[j].x) + abs(node[i].y - node[j].y);
            }
        }
        cout<<dij()<<endl;
        node.clear();
        graph.clear();
    }
    return 0;
}