#include <iostream>
#include <vector>
#include <algorithm>

#include "tools.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> v1, v2;
        if (root == nullptr)
            return v2;
        queue<TreeNode *> q;
        int i;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;

            for (i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }

            v1.push_back(v);
        }

        int n = v1.size();
        for (i = n - 1; i >= 0; i--)
        {
            v2.push_back(v1[i]);
        }

        return v2;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    vector<int> v = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    // vector<int> v = {2, 7, 5, 2, 6, 3, 6, 5, 8, 4, 5, 8, 4, 5, 8};
    TreeNode *t = TreeCreate(v);
    TreePrint(t);

    vector<vector<int>> v2 = pS->levelOrderBottom(t);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << i << " : ";

        for (int j = 0; j < v2[i].size(); j++)
        {
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }

    TreeDestroy(t);

    delete pS;
    return 0;
}
