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
        // iterate
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *n;

        while (root != nullptr || !s.empty())
        {
            if (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                n = s.top();
                s.pop();
                v.push_back(n->val);

                if (n->right != nullptr)
                {
                    root = n->right;
                }
            }
        }
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
    vector<int> v2 = pS->inorderTraversal(t);
    VectorPrint(v2);

    TreeDestroy(t);

    delete pS;
    return 0;
}
