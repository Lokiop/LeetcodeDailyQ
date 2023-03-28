#include <bits/stdc+.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &cost)
    {
        vector<int> dp(366, 0);
        for (auto &day : days)
        {
            dp[day] = 1;
        }

        for (int i = 1; i <= 365; i++)
        {
            if (!dp[i])
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = min({dp[i - 1] + cost[0], dp[max(0, i - 7)] + cost[1],
                             dp[max(0, i - 30)] + cost[2]});
            }
        }

        return dp[365];
    }
};