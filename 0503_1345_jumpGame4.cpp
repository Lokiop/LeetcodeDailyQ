#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        unordered_map<int, vector<int>> m;
        int sz = arr.size();
        for (int i = 0; i < sz; i++)
        {
            m[arr[i]].push_back(i);
        }

        vector<bool> visited(sz);

        int jumps = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int a = q.front();
                q.pop();
                if (a == sz - 1)
                    return jumps;

                if (a - 1 >= 0 && !visited[a - 1])
                {
                    q.push(a - 1);
                    visited[a - 1] = true;
                }

                if (a + 1 < sz && !visited[a + 1])
                {
                    q.push(a + 1);
                    visited[a + 1] = true;
                }

                for (auto &i : m[arr[a]])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }

                m[arr[a]].clear();
            }
            jumps++;
        }

        return jumps;
    }
};

int main()
{

    return 0;
}