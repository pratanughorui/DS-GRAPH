// 380  Snake and Ladders Problem
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int solve(vector<vector<int>> v)
{
    int n = v.size();
    int target = n * n;
    queue<int> q;
    q.push(1);
    int step = 0;
    vector<vector<bool>> vis[n][n];

    int m = n - 1;
    while (!q.empty() or step != target)
    {
        int s = q.size();
        while (s--)
        {
            int x = q.front();
            if (x == target)
                return step;
            for (int k = 1; k <= 6; k++)
            {
                if (k + x > target)
                    break;
                int pos[] = findco(k + x, n);
                int r = pos[0];
                int c = pos[1];
                if (vis[r][c] == 1)
            }
        }
    }
    return 0;
}
int main()
{

    vector<vector<int>> v{{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    cout << solve(v);
}