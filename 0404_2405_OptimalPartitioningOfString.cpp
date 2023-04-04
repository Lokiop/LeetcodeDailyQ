#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionString(string s)
    {
        unordered_map<char, int> mp;
        int ans = 1, start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.count(s[i]) && mp[s[i]] >= start)
            {
                ans++;
                start = i;
            }
            mp[s[i]] = i;
        }

        return ans;
    }
};