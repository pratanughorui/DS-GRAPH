// 363  flood fill algo
#include <iostream>
#include <vector>
using namespace std;
void dfs(int x, int y, vector<vector<int>> &g, int m, int n, vector<vector<int>> &vis, int oldc, int newc)
{
    if (x < 0 or y < 0 or x >= m or y >= n)
        return;
    if (g[x][y] != oldc or vis[x][y] == 1)
        return;
    vis[x][y] = 1;
    g[x][y] = newc;
    dfs(x - 1, y, g, m, n, vis, oldc, newc);
    dfs(x, y + 1, g, m, n, vis, oldc, newc);
    dfs(x + 1, y, g, m, n, vis, oldc, newc);
    dfs(x, y - 1, g, m, n, vis, oldc, newc);
}
int main()
{

    vector<vector<int>> g{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int i = 1, j = 1;
    int newcolor = 2;
    int m = g.size();
    int n = g[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int oldcolor = g[i][j];
    dfs(i, j, g, m, n, vis, oldcolor, newcolor);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}