// 358 Implement DFS Algo
#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &vis, int v, vector<int> g[], int src)
{
    int n = src;
    cout << n;
    for (int x : g[n])
    {
        if (vis[x] == 0)
        {
            vis[x] = 1;
            solve(vis, v, g, x);
        }
    }
}
void dfs(vector<int> g[], int v)
{
    vector<int> vis(v, 0);
    vis[0] = 1;
    solve(vis, v, g, 0);
}
int main()
{

    int v, e;
    cin >> v >> e;
    vector<int> g[v]; // only row is initialized and column will initiaze later
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(g, v);
}