#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> root, rank;
    int find(int x)
    {
        return root[x] == x ? x : root[x] = find(root[x]);
    }

    void Union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;
        if (rank[rootX] > rank[rootY])
        {
            root[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY])
        {
            root[rootX] = rootY;
        }
        else
        {
            root[rootY] = rootX;
            rank[rootX]++;
        }
    }

public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        root.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            root[i] = i;
        }

        for (auto &it : roads)
        {
            Union(it[0], it[1]);
        }

        int root1 = root[1];
        int ans = INT_MAX;
        for (auto &it : roads)
        {
            int x = find(it[0]);
            if (x == root1)
            {
                ans = min(ans, it[2]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}