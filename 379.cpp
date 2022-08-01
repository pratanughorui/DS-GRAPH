#include <iostream>
#include <vector>
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
        g[y].push_back(x);
    }
    vector<int> color(v, -1);
    vector<int> step(v, -1);
    color[0] = 0;
    for (int i = 1; i < v; i++)
    {
        for (int x : g[i])
        {
            if (color[x] != -1)
            {
                step[x] = 1;
            }
        }
        for (int j = 0; j < v; j++)
        {
            if (step[j] == -1)
            {
                color[i] = j;
                break;
            }
        }
        step.resize(v, -1);
    }
    for (int i = 0; i < v; i++)
    {
        cout << color[i] << " ";
    }
}