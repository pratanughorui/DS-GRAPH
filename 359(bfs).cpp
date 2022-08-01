#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check_cycle(vector<int> g[], int v)
{
    vector<int> ndig(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int x : g[i])
        {
            ndig[x]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (ndig[i] == 0)
        {
            q.push(i);
        }
    }
    int c = q.size();
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (int x : g[a])
        {
            ndig[x]--;
            if (ndig[x] == 0)
            {
                q.push(x);
                c++;
            }
        }
    }
    if (c == v)
        return false;
    else
        return true;
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> g[v]; // only row is initialized and column will initiaze later
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    cout << check_cycle(g, v);
}