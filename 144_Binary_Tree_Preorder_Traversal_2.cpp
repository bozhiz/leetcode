#include <iostream>
#include <vector>
#include <algorithm>

#include "tools.hpp"

using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // iteratively
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *n = root;

        if (n != nullptr)
            s.push(n);

        while (!s.empty())
        {
            n = s.top();
            v.push_back(n->val);
            s.pop();

            if (n->right != nullptr)
                s.push(n->right);
            if (n->left != nullptr)
                s.push(n->left);
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
    vector<int> v2 = pS->preorderTraversal(t);
    VectorPrint(v2);

    TreeDestroy(t);

    delete pS;
    return 0;
}
