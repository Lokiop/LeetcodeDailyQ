#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string ans;
        int n = 0;
        for (auto &it : s)
        {
            if (it != '*')
                ans += it;
            else
                ans.pop_back();
        }

        return ans;
    }
};