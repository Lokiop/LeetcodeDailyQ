#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;

    bool bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        bool flag = false;
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                flag = true;

            for (int k = 0; k < 4; k++)
            {
                int r = i + dx[k];
                int c = j + dy[k];
                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 0)
                {
                    q.push({r, c});
                    vis[r][c] = 1;
                }
            }
        }

        return flag;
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0 && !vis[i][j])
                {
                    ans++;
                    if (bfs(i, j, vis, grid))
                    {
                        ans--;
                    }
                }
            }
        }

        return ans;
    }
};