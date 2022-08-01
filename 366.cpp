// 366  word Ladder
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int ll(string brg, string end, vector<string> wd)
{
    map<string, int> m;
    for (int i = 0; i < wd.size(); i++)
    {
        m[wd[i]] = 1;
    }
    if (m[end] != 1)
        return 0;
    int len = 0;
    queue<string> q;
    q.push(brg);
    int sa = brg.size();
    while (!q.empty())
    {
        len++;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            string s = q.front();

            q.pop();
            for (int j = 0; j < sa; j++)
            {
                char org = s[j];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    s[j] = ch;
                    if (s == end)
                        return len + 1;
                    if (m[s] != 1)
                    {
                        continue;
                    }
                    m.erase(s);
                    q.push(s);
                }
                s[j] = org;
            }
        }
    }
    return 0;
}
int main()
{
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    cout << ll("hit", "cog", wordList);
}