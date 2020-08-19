#ifndef __TOOLS_HPP__
#define __TOOLS_HPP__

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdarg>
#include <string>
#include <vector>
#include <queue>
#include <list>
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

ListNode *ListCreate(const vector<int> &vec);
void ListDestroy(ListNode *head);
void ListPrint(ListNode *head);

TreeNode *TreeCreate(const vector<int> &vec);
TreeNode *TreeCreate(const vector<int> &vec, int i);
void TreeDestroy(TreeNode *root);
void TreePrint(TreeNode *root);

#endif