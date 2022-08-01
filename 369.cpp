// 369  Minimum time taken by each job to be completed given by a Directed Acyclic Graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> g[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    vector<int> ndig(v, 0);
    ndig[0] = 0;
    for (int i = 0; i < v; i++)
    {
        for (int x : g[i])
        {
            ndig[x]++;
        }
    }
    queue<int> q;
    vector<int> time(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (ndig[i] == 0)
        {
            time[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty())
    {

        int src = q.front();
        q.pop();
        for (int x : g[src])
        {
            ndig[x]--;
            if (ndig[x] == 0)
            {
                time[x] = time[src] + 1;
                q.push(x);
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << time[i] << " ";
    }
}