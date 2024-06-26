#include<iostream>
#include<vector>
#define INT_MAX 9999
using namespace std;

int n,f1,f2,f3,g1,g2,g3,ans = INT_MAX;
vector<int> visited;
void explore(int start, int end)
{
    if(start == end)
    {
        int cost =0;
        int i =0;
        for(;i<f1; i++)
        {
            cost+= abs(visited[i]-g1);
        }
        for(int j=0; j<f2; j++)
        {
            cost+= abs(visited[i]-g2);
            i++;
        }
        for(int k=0;k<f3; k++)
        {
            cost+= abs(visited[i]-g3);
            i++;
        }
        cost += i;
        ans = min(ans, cost);
        return;
    }else{
        for(int i = start; i<=end; i++)
        {
            swap(visited[i], visited[start]);
            explore(start+1, end);
            swap(visited[i], visited[start]);
        }
    }
}
int main()
{
    cin>>n;
    cin>>g1>>g2>>g3>>f1>>f2>>f3;
    visited.assign(n, 0);
    for(int i=0;i<n;i++)
    {
        visited[i] = i+1;
    }
    explore(0, n-1);
    cout<<ans<<endl;
    return 0;
}