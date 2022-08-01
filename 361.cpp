// 361  Search in a Maze
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> ans;
void solve(int i, int j, vector<vector<int>> m, int n, vector<vector<int>> &vis, string s)
{
    if (i < 0 or j < 0 or i >= n or j >= n)
    {
        return;
    }
    if (m[i][j] == 0 or vis[i][j] == 1)
    {
        return;
    }
    if (i == n - 1 and j == n - 1)
    {
        ans.push_back(s);
        return;
    }
    vis[i][j] = 1;
    solve(i + 1, j, m, n, vis, s + 'D');
    solve(i, j + 1, m, n, vis, s + 'R');
    solve(i - 1, j, m, n, vis, s + 'U');
    solve(i, j - 1, m, n, vis, s + 'L');
    vis[i][j] = 0;
}
vector<string> find_path(vector<vector<int>> m, int n)
{
    int i = 0, j = 0;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    solve(i, j, m, n, vis, "");
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> m{{1, 0, 0, 0},
                          {1, 1, 0, 1},
                          {1, 1, 0, 0},
                          {0, 1, 1, 1}};
    int n = 4;
    vector<string> ans = find_path(m, n);
    for (string x : ans)
    {
        cout << x << " ";
    }
}