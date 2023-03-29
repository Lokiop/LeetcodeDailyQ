#include <bits/stdc+.h>
using namespace std;

class Solution
{
    int rec(int i, vector<int> &arr, int time, vector<vector<int>> &dp)
    {
        if (i >= arr.size())
            return 0;
        if (dp[i][time] != -1)
            return dp[i][time];
        return dp[i][time] = max(rec(i + 1, arr, time, dp),
                                 arr[i] * time + rec(i + 1, arr, time + 1, dp));
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return rec(0, satisfaction, 1, dp);

        //     for(int i = n-1; i>=0; i--)
        //     {
        //         for(int j = n; j>=1; j--)
        //         {
        //             dp[i][j] = max(dp[i+1][j], satisfaction[i]*j+dp[i+1][j+1]);
        //         }
        //     }

        //     return dp[0][1];
    }