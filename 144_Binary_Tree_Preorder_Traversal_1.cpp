#include <iostream>
#include <vector>
#include <algorithm>

#include "tools.hpp"

using namespace std;

class Solution
{
private:
    vector<int> v;
    void preorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // recursive

        preorder(root);

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
    vector<int> v2 = pS->preorderTraversal(t);
    VectorPrint(v2);

    TreeDestroy(t);

    delete pS;
    return 0;
}
