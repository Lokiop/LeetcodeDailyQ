#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool canEat(vector<int> &a, int mid, int h)
    {
        int t = 0;
        for (auto &it : a)
        {
            t += ((it + mid - 1) / mid); // same as taking the ceil value of it/mid;
            if (t > h)
                return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (canEat(piles, mid, h))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};

int main()
{

    return 0;
}