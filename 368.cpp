// 368  Implement Topological Sort
#include <iostream>
#include <vector>
using namespace std;
int index(vector<int> n, int v)
{
    int a;
    for (int i = 0; i < v; i++)
    {
        if (n[i] == 0)
        {
            a = i;
            break;
        }
    }

    return a;
}
void topo(vector<int> g[], int v)
{
    vector<int> ndig(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int x : g[i])
        {
            ndig[x]++;
        }
    }
    for (int i = 0; i < v; i++)
    {
        int ind = index(ndig, v);
        cout << ind << " ";
        ndig[ind] = -1;
        for (int x : g[ind])
        {
            ndig[x] -= 1;
        }
    }
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

    topo(g, v);
}