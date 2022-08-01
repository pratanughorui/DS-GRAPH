#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    vector<vector<int>> g;
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t;

        g.push_back({u, v, w});
    }
    vector<int> dis(v, INT_MAX);
    dis[0] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        for (auto x : g)
        {
            int u = x[0]; // 0 1 2
            int v = x[1]; // 1  2  0
            int w = x[2]; //-1 -2  3
            if (dis[u] + w < dis[v] and dis[u] != INT_MAX)
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << dis[i] << " ";
    }
}