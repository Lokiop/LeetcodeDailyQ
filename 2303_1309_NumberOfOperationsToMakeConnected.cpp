#include <bits/stdc++.h>
using namespace std;

// Approach 1 Usind dfs
class Solution1
{
    void dfs(int s, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[s] = 1;
        for (auto &it : adj[s])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);
        for (auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        vector<int> vis(n, 0);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, vis, adj);
            }
        }

        return cnt - 1;
    }
};

// Approach 2 using Union Find
class Solution2
{
    vector<int> rank;
    vector<int> parent;

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int parX = find(x);
        int parY = find(y);
        if (parX == parY)
            return;
        if (rank[parX] < rank[parY])
        {
            parent[parX] = parY;
        }
        else if (rank[parX] > rank[parY])
        {
            parent[parY] = parX;
        }
        else
        {
            parent[parY] = parX;
            rank[parX]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        rank.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }

        for (auto &connection : connections)
        {
            Union(connection[0], connection[1]);
        }

        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(find(i));
        }

        return s.size() - 1;
    }
};