// 357 Implement BFS algorithm
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<int> g[], int v)
{
    queue<int> q;
    q.push(0);
    vector<int> vis(v, 0);
    vis[0] = 1;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        cout << a << " ";
        for (int x : g[a])
        {
            if (vis[x] == 0)
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
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
    bfs(g, v);
}