#include <iostream>
#include <vector>
#include <algorithm>

#include "tools.hpp"

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || preorder.size() != inorder.size())
            return nullptr;

        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd)
    {
        int preorderRoot, inorderRoot, len;
        preorderRoot = preorderStart;

        if (preorderStart > preorderEnd || inorderStart > inorderStart)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preorderRoot]);
        if (preorderStart == preorderEnd)
            return root;

        for (inorderRoot = inorderStart; inorderRoot <= inorderEnd; inorderRoot++)
            if (inorder[inorderRoot] == preorder[preorderRoot])
                break;

        len = inorderRoot - inorderStart;
        root->left = helper(preorder, inorder, preorderStart + 1, preorderStart + len, inorderStart, inorderRoot - 1);
        root->right = helper(preorder, inorder, preorderStart + len + 1, preorderEnd, inorderRoot + 1, inorderEnd);

        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> inorder = {2, 1};
    // vector<int> postorder = {1, 2};

    TreeNode *t = pS->buildTree(preorder, inorder);
    TreePrint(t);
    TreeDestroy(t);

    return 0;
}
