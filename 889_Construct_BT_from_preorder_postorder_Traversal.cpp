#include "tools.hpp"

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &postorder)
    {
        if (preorder.size() == 0 || preorder.size() != postorder.size())
            return nullptr;

        return helper(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    TreeNode *helper(vector<int> &preorder, vector<int> &postorder, int preorderStart, int preorderEnd, int postOrderStart, int postOrderEnd)
    {
        int preorderRight, len;

        if (preorderStart > preorderEnd || postOrderStart > postOrderStart)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postOrderEnd]);
        if (postOrderStart == postOrderEnd)
            return root;

        for (preorderRight = preorderStart + 1; preorderRight <= preorderEnd; preorderRight++)
            if (preorder[preorderRight] == postorder[postOrderEnd - 1])
                break;

        len = preorderRight - preorderStart - 1;
        root->left = helper(preorder, postorder, preorderStart + 1, preorderRight - 1, postOrderStart, postOrderStart + len - 1);
        root->right = helper(preorder, postorder, preorderRight, preorderEnd, postOrderStart + len, postOrderEnd - 1);

        return root;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();
    /*
         3       
        / \   
        /   \  
        9   20   
            / \ 
           15  7 
     */
    vector<int> pre1 = {3, 9, 20, 15, 7};
    vector<int> post1 = {9, 15, 7, 20, 3};

    TreeNode *t = pS->buildTree(pre1, post1);
    TreePrint(t);
    TreeDestroy(t);

    /*
        2   
         \ 
          1 
     */
    vector<int> pre2 = {2, 1};
    vector<int> post2 = {1, 2};
    t = pS->buildTree(pre2, post2);
    TreePrint(t);
    TreeDestroy(t);

    return 0;
}
