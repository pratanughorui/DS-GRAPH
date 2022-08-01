// 362  Minimum Step by Knight
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int minstep(vector<int> &knightPos, vector<int> &TargetPos, int n)
{
    int s1 = knightPos[0];
    int s2 = knightPos[1];
    int t1 = TargetPos[0];
    int t2 = TargetPos[1];
    queue<pair<int, int>> q;
    int vis[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vis[i][j] = 0;
        }
    }
    q.push(make_pair(s1 - 1, s2 - 1));
    while (!q.empty())
    {
        auto cur = q.front();
        int i = cur.first;
        int j = cur.second;
        q.pop();
        if (i + 1 >= 0 and i + 1 < n and j + 2 >= 0 and j + 2 < n and vis[i + 1][j + 2] == 0)
        {
            vis[i + 1][j + 2] = vis[i][j] + 1;
            q.push(make_pair(i + 1, j + 2));
        }
        if (i + 1 >= 0 and i + 1 < n and j - 2 >= 0 and j - 2 < n and vis[i + 1][j - 2] == 0)
        {
            vis[i + 1][j - 2] = vis[i][j] + 1;
            q.push(make_pair(i + 1, j - 2));
        }
        if (i - 1 >= 0 and i - 1 < n and j + 2 >= 0 and j + 2 < n and vis[i - 1][j + 2] == 0)
        {
            vis[i - 1][j + 2] = vis[i][j] + 1;
            q.push(make_pair(i - 1, j + 2));
        }
        if (i - 1 >= 0 and i - 1 < n and j - 2 >= 0 and j - 2 < n and vis[i - 1][j - 2] == 0)
        {
            vis[i - 1][j - 2] = vis[i][j] + 1;
            q.push(make_pair(i - 1, j - 2));
        }
        if (i + 2 >= 0 and i + 2 < n and j - 1 >= 0 and j - 1 < n and vis[i + 2][j - 1] == 0)
        {
            vis[i + 2][j - 1] = vis[i][j] + 1;
            q.push(make_pair(i + 2, j - 1));
        }
        if (i + 2 >= 0 and i + 2 < n and j + 1 >= 0 and j + 1 < n and vis[i + 2][j + 1] == 0)
        {
            vis[i + 2][j + 1] = vis[i][j] + 1;
            q.push(make_pair(i + 2, j + 1));
        }
        if (i - 2 >= 0 and i - 2 < n and j - 1 >= 0 and j - 1 < n and vis[i - 2][j - 1] == 0)
        {
            vis[i - 2][j - 1] = vis[i][j] + 1;
            q.push(make_pair(i - 2, j - 1));
        }
        if (i - 2 >= 0 and i - 2 < n and j + 1 >= 0 and j + 1 < n and vis[i - 2][j + 1] == 0)
        {
            vis[i - 2][j + 1] = vis[i][j] + 1;
            q.push(make_pair(i - 2, j + 1));
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return vis[t1 - 1][t2 - 1];
}
int main()
{
    vector<int> KnightPos{4, 5};
    vector<int> TargetPos{1, 1};
    cout << minstep(KnightPos, TargetPos, 6);
}