// 356  Create a Graph, print it
#include <iostream>
#include <vector>
using namespace std;
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
        g[y].push_back(x);
    }
    cout << "graph is: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "-->";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}