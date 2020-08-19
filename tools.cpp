#include "tools.hpp"

/**
 * 
 * 
 */
void VectorPrint(const vector<int> &v)
{
    for (auto n : v)
        cout << n << " ";
    cout << endl;
}

/**
 * leetcode for singly-linked list operation.
 */
ListNode *ListCreate(const vector<int> &vec)
{
    size_t size = vec.size();
    ListNode *head, *curr;

    if (size == 0)
    {
        return nullptr;
    }

    head = new ListNode(vec[0]);
    curr = head;
    for (size_t i = 1; i < size; i++)
    {
        ListNode *tmp = new ListNode(vec[i]);

        curr->next = tmp;
        curr = tmp;
    }

    return head;
}

void ListDestroy(ListNode *head)
{
    ListNode *curr = head;
    ListNode *temp = nullptr;
    while (curr != nullptr)
    {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void ListPrint(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

/**
 * leetcode binary tree operation
 */
// TreeNode *TreeCreate(const vector<int> &vec)
// {
//     size_t size = vec.size();
//     TreeNode **treeArr = new TreeNode *[size];
//     for (size_t i = 0; i < size; i++)
//     {
//         if (INT_MAX == vec[i])
//         {
//             treeArr[i] = nullptr;
//         }
//         else
//         {
//             treeArr[i] = new TreeNode(vec[i]);
//         }
//     }

//     size_t curr = 1;
//     for (size_t i = 0; i < size; i++)
//     {
//         if (!treeArr[i])
//         {
//             continue;
//         }

//         if (curr < size)
//         {
//             treeArr[i]->left = treeArr[curr++];
//         }
//         if (curr < size)
//         {
//             treeArr[i]->right = treeArr[curr++];
//         }
//     }

//     TreeNode *root = treeArr[0];
//     delete[] treeArr;
//     return root;
// }

TreeNode *TreeCreate(const vector<int> &vec)
{
    size_t size = vec.size();
    vector<TreeNode *> v;
    TreeNode *n;

    for (size_t i = 0; i < size; i++)
    {
        if (INT_MAX == vec[i])
        {
            n = nullptr;
        }
        else
        {
            n = new TreeNode(vec[i]);
        }

        v.push_back(n);
    }

    size_t curr = 1;
    for (size_t i = 0; i < size; i++)
    {
        if (nullptr == v[i])
        {
            continue;
        }

        if (curr < size)
        {
            v[i]->left = v[curr++];
        }
        if (curr < size)
        {
            v[i]->right = v[curr++];
        }
    }

    return v[0];
}

TreeNode *TreeCreate(const vector<int> &vec, int i)
{
    size_t n = vec.size();
    TreeNode *root = new TreeNode(vec[i]);

    int left = 2 * i + 1;
    if (left < n && vec[left] != INT_MAX)
        root->left = TreeCreate(vec, left);

    int right = 2 * i + 2;
    if (right <= n && vec[right] != INT_MAX)
        root->right = TreeCreate(vec, right);

    return root;
}

void TreeDestroy(TreeNode *root)
{
    if (nullptr == root)
    {
        return;
    }
    TreeDestroy(root->left);
    TreeDestroy(root->right);
    delete root;
}

static int TreeMaxLevel(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    return max(TreeMaxLevel(root->left), TreeMaxLevel(root->right)) + 1;
}

static void TreePrintWhitespaces(int count)
{
    for (int i = 0; i < count; i++)
        cout << " ";
}

bool TreeIsAllElementsNull(vector<TreeNode *> &v)
{
    for (auto node : v)
        if (node != nullptr)
            return false;

    return true;
}

static void TreePrintNodeInternal(vector<TreeNode *> &v, int level, int maxLevel)
{
    if (v.empty() || TreeIsAllElementsNull(v))
        return;

    int floor = maxLevel - level;
    int endgeLines = (int)pow(2, max(floor - 1, 0));
    int firstSpaces = (int)pow(2, (floor)) - 1;
    int betweenSpaces = (int)pow(2, (floor + 1)) - 1;

    TreePrintWhitespaces(firstSpaces);

    vector<TreeNode *> newV;
    for (int i = 0; i < v.size(); i++)
    {
        TreeNode *node = v[i];
        if (node != nullptr)
        {
            cout << node->val;
            newV.push_back(node->left);
            newV.push_back(node->right);
        }
        else
        {
            newV.push_back(nullptr);
            newV.push_back(nullptr);
            cout << " ";
        }

        TreePrintWhitespaces(betweenSpaces);
    }

    cout << endl;

    for (int i = 1; i <= endgeLines; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            TreePrintWhitespaces(firstSpaces - i);
            if (v[j] == nullptr)
            {
                TreePrintWhitespaces(endgeLines + endgeLines + i + 1);
                continue;
            }

            if (v[j]->left != nullptr)
                cout << "/";
            else
                TreePrintWhitespaces(1);

            TreePrintWhitespaces(i + i - 1);

            if (v[j]->right != nullptr)
                cout << "\\";
            else
                TreePrintWhitespaces(1);

            TreePrintWhitespaces(endgeLines + endgeLines - i);
        }

        cout << endl;
    }

    TreePrintNodeInternal(newV, level + 1, maxLevel);
}

void TreePrint(TreeNode *root)
{
    int maxLevel = TreeMaxLevel(root);
    vector<TreeNode *> v;
    v.push_back(root);

    TreePrintNodeInternal(v, 1, maxLevel);
}
