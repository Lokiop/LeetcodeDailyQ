#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dfs(int i, int coins, vector<vector<int>> &piles, vector<vector<int>> &dp)
    {
        if (i == piles.size() || coins == 0)
            return 0;
        if (dp[i][coins] != -1)
            return dp[i][coins];

        // go to the next pile
        dp[i][coins] = dfs(i + 1, coins, piles, dp);
        int currPile = 0;
        for (int j = 0; j < piles[i].size() && j < coins; j++)
        {
            // take as many coins from the current pile
            currPile += piles[i][j];

            // go to the next pile
            dp[i][coins] = max(dp[i][coins], currPile + dfs(i + 1, coins - j - 1, piles, dp));
        }

        // return the maximum value
        return dp[i][coins];
    }

public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        vector<vector<int>> dp(piles.size(), vector<int>(k + 1, -1));
        return dfs(0, k, piles, dp);
    }
};