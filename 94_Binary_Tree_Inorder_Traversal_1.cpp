#include <iostream>
#include <vector>
#include <algorithm>

#include "tools.hpp"

using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        // recursive
        inorder(root);
        return v;
    }

private:
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->left)
            inorder(root->left);
        v.push_back(root->val);
        if (root->right)
            inorder(root->right);
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    vector<int> v1 = {1, INT_MAX, 2, 3};
    VectorPrint(v1);

    TreeNode *t = TreeCreate(v1);
    TreePrint(t);
    vector<int> v2 = pS->inorderTraversal(t);
    VectorPrint(v2);

    TreeDestroy(t);

    return 0;
}
