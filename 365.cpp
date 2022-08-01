// 365  Making wired Connections
#include <iostream>
#include <vector>
using namespace std;
void dfs(int src, vector<int> g[], vector<int> &vis)
{
    vis[src] = 1;
    for (auto x : g[src])
    {
        if (vis[x] == 0)
        {
            dfs(x, g, vis);
        }
    }
}
int mc(int n, vector<vector<int>> &con)
{
    vector<int> g[n];
    int m = con.size();
    if (m < n - 1)
        return -1;
    for (int i = 0; i < m; i++)
    {
        g[con[i][0]].push_back(con[i][1]);
        g[con[i][1]].push_back(con[i][0]);
    }
    int c = 0;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            c++;
            dfs(i, g, vis);
        }
    }
    return c - 1;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> con;
    for (int i = 0; i < n - 1; i++)
    {
        vector<int> t;
        for (int j = 0; j < 2; j++)
        {
            int x;
            cin >> x;
            t.push_back(x);
        }
        con.push_back(t);
    }
    cout << mc(n, con);
}