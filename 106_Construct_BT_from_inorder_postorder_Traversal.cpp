#include <iostream>
#include <vector>
#include <algorithm>

#include "tools.hpp"

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || inorder.size() != postorder.size())
            return nullptr;

        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int inorderStart, int inorderEnd, int postOrderStart, int postOrderEnd)
    {
        int inorderRoot, postorderRoot, len;
        postorderRoot = postOrderEnd;

        if (inorderStart > inorderEnd || postOrderStart > postOrderStart)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postorderRoot]);
        if (inorderStart == inorderEnd)
            return root;

        for (inorderRoot = inorderStart; inorderRoot <= inorderEnd; inorderRoot++)
            if (inorder[inorderRoot] == postorder[postorderRoot])
                break;

        len = inorderRoot - inorderStart;
        root->left = helper(inorder, postorder, inorderStart, inorderRoot - 1, postOrderStart, postOrderStart + len - 1);
        root->right = helper(inorder, postorder, inorderRoot + 1, inorderEnd, postOrderStart + len, postOrderEnd - 1);

        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    // vector<int> inorder = {9, 3, 15, 20, 7};
    // vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {2, 1};
    vector<int> postorder = {1, 2};

    TreeNode *t = pS->buildTree(inorder, postorder);
    TreePrint(t);
    TreeDestroy(t);

    return 0;
}
