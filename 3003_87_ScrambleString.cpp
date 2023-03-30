#include <bits/stdc+.h>
using namespace std;

class Solution
{
    unordered_map<string, bool> mp;

public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        if (n != s2.size())
            return false;
        if (s1 == s2)
            return true;
        if (n == 1)
            return false;
        if (mp.count(s1 + s2))
            return mp[s1 + s2];

        for (int i = 1; i < n; i++)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
            {
                return mp[s1 + s2] = true;
            }

            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i)))
            {
                return mp[s1 + s2] = true;
            }
        }

        return mp[s1 + s2] = false;
    }
};