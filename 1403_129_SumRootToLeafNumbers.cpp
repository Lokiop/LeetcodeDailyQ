#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void rec(TreeNode *root, int currSum, int &ans)
    {
        if (!root)
        {
            return;
        }

        currSum = currSum * 10 + root->val;

        if (!root->left && !root->right)
        {
            ans += currSum;
            return;
        }

        rec(root->left, currSum, ans);
        rec(root->right, currSum, ans);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        rec(root, 0, ans);
        return ans;
    }
};

int main()
{

    return 0;
}