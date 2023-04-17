#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int e)
    {
        int n = candies.size();
        int a = candies[0];
        for (int i = 1; i < n; i++)
        {
            if (candies[i] > a)
                a = candies[i];
        }

        vector<bool> ans;
        for (int i = 0; i < n; i++)
        {
            if (e + candies[i] >= a)
            {
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }

        return ans;
    }
};