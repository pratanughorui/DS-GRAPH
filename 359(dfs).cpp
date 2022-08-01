// 359  Detect Cycle in Directed Graph using BFS/DFS Algo
#include <iostream>
#include <vector>
using namespace std;
bool solve(int i, vector<int> adj[], vector<int> &vis, vector<bool> &order)
{
    vis[i] = 1;
    order[i] = 1;
    for (auto x : adj[i])
    {
        if (vis[x] == 0)
        {
            bool con = solve(x, adj, vis, order);
            if (con == true)
            {
                return true;
            }
        }
        else if (order[x])
            return true;
    }
    order[i] = 0;
    return false;
}
bool check_cycle(vector<int> g[], int v)
{
    vector<int> vis(v, 0);
    vector<bool> order(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            bool ans = solve(i, g, vis, order);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
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
    }
    cout << check_cycle(g, v);
}