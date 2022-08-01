// 367  Dijkstra algo
#include <iostream>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;
void dijkstra(vector<pair<int, int>> g[], int v)
{
    vector<int> vis(v, 0);
    vector<int> dis(v, INT_MAX);
    dis[0] = 0;
    set<pair<int, int>> s;
    s.insert({0, 0});
    while (!s.empty())
    {
        auto temp = *s.begin();
        int a = temp.first;
        int b = temp.second;
        s.erase(s.begin());
        if (vis[b] == 1)
            continue;
        vis[b] = 1;
        for (auto x : g[b])
        {
            if (dis[b] + x.second < dis[x.first])
            {
                dis[x.first] = dis[b] + x.second;
                s.insert({x.second, x.first});
            }
        }
    }
    for (int x : dis)
    {
        cout << x << " ";
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> g[v];
    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }
    dijkstra(g, v);
}