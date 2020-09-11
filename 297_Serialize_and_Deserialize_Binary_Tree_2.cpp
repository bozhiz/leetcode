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
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (root)
        {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }

    TreeNode *deserialize(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "#")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
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
