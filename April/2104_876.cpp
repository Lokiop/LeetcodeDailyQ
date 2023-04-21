#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        vector<vector<vector<int>>> dp(group.size() + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        dp[0][0][0] = 1;
        for (int k = 1; k <= group.size(); k++)
        {
            int g = group[k - 1];
            int p = profit[k - 1];
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= minProfit; j++)
                {
                    dp[k][i][j] = dp[k - 1][i][j];
                    if (i >= g)
                    {
                        dp[k][i][j] = (dp[k][i][j] + dp[k - 1][i - g][max(0, j - p)]) % mod;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum = (sum + dp[group.size()][i][minProfit]) % mod;
        }
        return sum;
    }
};