#include <iostream>
#include <vector>
#include <algorithm>

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
        TreeNode *n;

        if (root == nullptr)
            return v;
        s.push(root);

        while (!s.empty())
        {
            n = s.top();
            v.push_back(n->val);
            s.pop();

            if (n->left != nullptr)
                s.push(n->left);

            if (n->right != nullptr)
                s.push(n->right);
        }

        reverse(v.begin(), v.end());
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

    delete pS;
    return 0;
}
