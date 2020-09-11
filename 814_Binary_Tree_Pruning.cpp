#include "tools.hpp"

using namespace std;

class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        if (root->left)
            root->left = pruneTree(root->left);
        if (root->right)
            root->right = pruneTree(root->right);

        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();

    // vector<int> v1 = {1, INT_MAX, 0, 0, 1};
    // TreeNode *t1 = TreeCreate(v1);
    // TreePrint(t1);
    // TreePrint(pS->pruneTree(t1));
    // TreeDestroy(t1);

    vector<int> v2 = {0, INT_MAX, 0, 0, 0};
    TreeNode *t2 = TreeCreate(v2);
    TreePrint(t2);
    TreeNode *t21 = pS->pruneTree(t2);
    TreePrint(t21);
    TreeDestroy(t21);

    delete pS;
    return 0;
}
