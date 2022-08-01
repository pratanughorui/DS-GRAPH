// 387  Cheapest Flights Within K Stop
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int v = INT_MAX;
void solve(vector<pair<int, int>> g[], int src, int dest, int k, int cost, int &c, int &step)
{
    if (src == dest)
    {

        v = min(v, c);
        return;
    }
    if (step > k)
    {
        step--;
        c -= cost;
        return;
    }
    for (auto x : g[src])
    {
        step++;
        c += x.second;

        solve(g, x.first, dest, k, x.second, c, step);
    }
}
int cheap(vector<pair<int, int>> g[], int src, int dest, int k)
{
    int cost = 0;
    int c = 0;
    int step = 0;
    solve(g, src, dest, k, cost, c, step);
    if (v == INT_MAX)
    {
        return -1;
    }
    else
    {
        return v;
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> g[v];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    cout << cheap(g, 0, 3, 1);
}