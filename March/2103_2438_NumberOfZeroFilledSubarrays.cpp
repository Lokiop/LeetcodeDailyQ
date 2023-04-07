#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        ll count = 0;
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                count++;
                ans += count;
            }
            else
            {
                count = 0;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}