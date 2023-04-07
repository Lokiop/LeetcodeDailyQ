#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        for (auto &connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(-connection[0]);
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for (auto &it : adj[node])
            {
                if (!vis[abs(it)])
                {
                    q.push(abs(it));
                    if (it > 0)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};