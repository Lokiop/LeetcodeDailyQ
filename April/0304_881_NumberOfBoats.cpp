#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0;
        for (int j = people.size() - 1; j >= i; j--)
        {
            if (limit - people[j] >= people[i])
                i++;
            ans++;
        }

        return ans;
    }
};