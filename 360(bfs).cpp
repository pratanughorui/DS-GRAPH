#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool solve(vector<int> g[], int s, int v, vector<bool> &vis)
{
    vector<int> p(v, -1);
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
                p[v] = u;
            }
            else if (p[u] != v)
                return true;
        }
    }
    return false;
}

bool check_cycle(vector<int> g[], int v)
{
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == false)
        {
            bool a = solve(g, i, v, vis);
            if (a == true)
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
    vector<int> g[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << check_cycle(g, v);
}