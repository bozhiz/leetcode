#ifndef __TOOLS_HPP__
#define __TOOLS_HPP__

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdarg>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void VectorPrint(const vector<int> &v);

ListNode *ListCreate(const vector<int> &vec);
void ListDestroy(ListNode *head);
void ListPrint(ListNode *head);

TreeNode *TreeCreate(const vector<int> &vec);
TreeNode *TreeCreate(const vector<int> &vec, int i);
void TreeDestroy(TreeNode *root);
void TreePrint(TreeNode *root);

#endif