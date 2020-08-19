#include <iostream>
#include <vector>
#include <algorithm>

#include "tools.hpp"

using namespace std;

class Solution
{
private:
    vector<int> v;

    void postorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->left != nullptr)
            postorder(root->left);
        if (root->right != nullptr)
            postorder(root->right);
        v.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        // recursive
        postorder(root);

        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    vector<int> v1 = {1, INT_MAX, 2, 3};
    VectorPrint(v1);

    TreeNode *t = TreeCreate(v1);
    TreePrint(t);
    vector<int> v2 = pS->postorderTraversal(t);
    VectorPrint(v2);

    TreeDestroy(t);

    return 0;
}
