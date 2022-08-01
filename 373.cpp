// 373  Implement Kruksal’sAlgorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parent;
int find(int a)
{
    if (parent[a] < 0)
    {
        return a;
    }
    return parent[a] = find(parent[a]);
}
void Union(int a, int b)
{
    parent[b] = a;
}
int main()
{
    int v, e;
    cin >> v >> e;
    parent.resize(v, -1);
    vector<pair<int, pair<int, int>>> g;
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> wt >> x >> y;
        g.push_back({wt, {x, y}});
    }
    sort(g.begin(), g.end());
    int total = 0;
    for (auto &x : g)
    {
        int wt = x.first;
        int u = x.second.first;
        int v = x.second.second;
        int a = find(u);
        int b = find(v);
        if (a != b)
        {
            Union(a, b);
            total += wt;
            cout << u << " " << v << endl;
        }
    }
    cout << total;
}
// https://www.hackerearth.com/challenges/hackathon/accenture-campus-students/