#include "tools.hpp"

using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        // iterate
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *n, *last;

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
                if (n->right != nullptr && n->right != last)
                {
                    root = n->right;
                }
                else
                {
                    v.push_back(n->val);
                    s.pop();
                    last = n;
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
    vector<int> v2 = pS->postorderTraversal(t);
    VectorPrint(v2);

    TreeDestroy(t);

    return 0;
}
