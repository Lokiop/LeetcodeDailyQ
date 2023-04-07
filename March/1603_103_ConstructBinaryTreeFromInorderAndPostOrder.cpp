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
    unordered_map<int, int> index;
    int postIndex;

    TreeNode *helper(int l, int r, vector<int> &postorder)
    {
        if (l > r)
            return NULL;

        int val = postorder[postIndex--];
        int ind = index[val];
        TreeNode *node = new TreeNode(val);

        node->right = helper(ind + 1, r, postorder);
        node->left = helper(l, ind - 1, postorder);

        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        postIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }

        return helper(0, inorder.size() - 1, postorder);
    }
};

int main()
{

    return 0;
}