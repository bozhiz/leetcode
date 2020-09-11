#include "tools.hpp"

using namespace std;

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int ans = INT_MIN;
        dfs(root, ans);

        return ans;
    }

private:
    int dfs(TreeNode *root, int &ans)
    {
        int l = 0, r = 0, levelMax = 0;
        vector<int> v;
        v.push_back(root->val);

        if (root->left)
        {
            l = dfs(root->left, ans);
            v.push_back(l);
        }
        if (root->right)
        {
            r = dfs(root->right, ans);
            v.push_back(r);
        }

        v.push_back(root->val + l);
        v.push_back(root->val + r);
        v.push_back(root->val + l + r);

        sort(v.begin(), v.end(), greater<int>());
        ans = max(ans, v[0]);

        return max(root->val, max(root->val + l, root->val + r));
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();

    vector<int> v1 = {9, 6, -3, INT_MAX, INT_MAX, -6, 2, INT_MAX, INT_MAX, 2, INT_MAX, -6, -6, -6};
    // vector<int> v1 = {-3};
    // vector<int> v1 = {-10, 9, 20, INT_MAX, INT_MAX, 15, 7};
    TreeNode *t1 = TreeCreate(v1);
    TreePrint(t1);
    cout << pS->maxPathSum(t1) << endl;
    TreeDestroy(t1);

    delete pS;
    return 0;
}
