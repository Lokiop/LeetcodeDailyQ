#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long dfs(int s, vector<int> &vis, vector<vector<int>> &adj)
    {
        long long cnt = 1;
        vis[s] = 1;
        for (auto &it : adj[s])
        {
            if (!vis[it])
            {
                cnt += dfs(it, vis, adj);
            }
        }

        return cnt;
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long ans = 0;
        long long nodes = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                long long cnt = dfs(i, vis, adj);
                ans += cnt * nodes;
                nodes += cnt;
            }
        }

        return ans;
    }
};