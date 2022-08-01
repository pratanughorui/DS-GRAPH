// 371  Find the no. of Isalnds
#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &grid, int i, int j)
{
    grid[i][j] = 0;
    int n = grid.size() - 1;
    int m = grid[0].size() - 1;
    if (i <= n and i >= 0 and j - 1 <= m and j - 1 >= 0 and grid[i][j - 1] == 1)
    {
        dfs(grid, i, j - 1);
    }
    if (i <= n and i >= 0 and j + 1 <= m and j + 1 >= 0 and grid[i][j + 1] == 1)
    {
        dfs(grid, i, j + 1);
    }
    if (i - 1 <= n and i - 1 >= 0 and j <= m and j >= 0 and grid[i - 1][j] == 1)
    {
        dfs(grid, i - 1, j);
    }
    if (i + 1 <= n and i + 1 >= 0 and j <= m and j >= 0 and grid[i + 1][j] == 1)
    {
        dfs(grid, i + 1, j);
    }
    if (i - 1 <= n and i - 1 >= 0 and j - 1 <= m and j - 1 >= 0 and grid[i - 1][j - 1] == 1)
    {
        dfs(grid, i - 1, j - 1);
    }
    if (i - 1 <= n and i - 1 >= 0 and j + 1 <= m and j + 1 >= 0 and grid[i - 1][j + 1] == 1)
    {
        dfs(grid, i - 1, j + 1);
    }
    if (i + 1 <= n and i + 1 >= 0 and j - 1 <= m and j - 1 >= 0 and grid[i + 1][j - 1] == 1)
    {
        dfs(grid, i + 1, j - 1);
    }
    if (i + 1 <= n and i + 1 >= 0 and j + 1 <= m and j + 1 >= 0 and grid[i + 1][j + 1] == 1)
    {
        dfs(grid, i + 1, j + 1);
    }
}
int numIsland(vector<vector<int>> grid)
{
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j);
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid{{0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 1, 0}};
    cout << numIsland(grid);
}