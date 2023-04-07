#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeArrayValue(vector<int> &a)
    {
        long sum = 0, res = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            sum += a[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};