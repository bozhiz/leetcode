#include "tools.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;
        TreeNode *node;
        ostringstream output;

        if (root == nullptr)
        {
            return output.str();
        }

        q.push(root);
        output << root->val << " ";

        while (!q.empty())
        {
            node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
                output << node->left->val << " ";
            }
            else
            {
                output << "# ";
            }
            if (node->right)
            {
                q.push(node->right);
                output << node->right->val << " ";
            }
            else
            {
                output << "# ";
            }
        }

        return output.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        istringstream input(data);
        string str;
        TreeNode *node = nullptr;
        vector<TreeNode *> v;
        int i, cur, size;

        while (input >> str && !str.empty())
        {
            if (str != "#")
                v.push_back(new TreeNode(stoi(str)));
            else
                v.push_back(nullptr);
        }

        size = v.size();
        for (i = 0, cur = 1; i < size && cur < size; i++)
        {
            if (v[i] == nullptr)
                continue;

            if (cur < size)
                v[i]->left = v[cur++];
            if (cur < size)
                v[i]->right = v[cur++];
        }

        return v[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char *argv[])
{
    Codec *pS = new Codec();

    vector<int> v1 = {1, 2, 3, INT_MAX, INT_MAX, 4, 5};
    VectorPrint(v1);

    TreeNode *t1 = TreeCreate(v1);
    TreePrint(t1);
    string str = pS->serialize(t1);
    cout << str << endl;
    TreeDestroy(t1);

    TreeNode *t2 = pS->deserialize(str);
    TreePrint(t2);
    TreeDestroy(t2);

    delete pS;
    return 0;
}
