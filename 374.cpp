#include <iostream>
#include <vector>
#include <set>
using namespace std;
void prims(vector<vector<int>> g[], int v)
{
    vector<int> vis(v, 0);
    set<pair<int, int>> s;
    s.insert({0, 0});
    int t = 0;
    while (!s.empty())
    {
        auto x = *s.begin();
        int wt = x.first;
        int u = x.second;
        s.erase(s.begin());
        if (vis[u] == 0)
        {
            vis[u] = 1;
            t += wt;
        }

        for (auto y : g[u])
        {
            if (vis[y[0]] == 0)
            {

                s.insert({y[1], y[0]});
            }
        }
    }
    cout << t;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g[v];
    for (int i = 0; i < e; i++)
    {

        int x, y, w;
        cin >> x >> y >> w;
        vector<int> t1, t2;
        t1.push_back(y);
        t1.push_back(w);
        g[x].push_back(t1);
        t2.push_back(x);
        t2.push_back(w);
        g[y].push_back(t2);
    }
    prims(g, v);
}