#include<iostream>  
#include<vector>
#include<map>
  
using namespace std; 

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int val = 0;
        ListNode *head = NULL;
        ListNode **node = &head;
        
        while(l1 || l2) {
            if(l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                val += l2->val;
                l2 = l2->next;
            }

            /*
            if(!head)
                head = node = new ListNode(val%10);
            else {
                node->next = new ListNode(val%10);
                node = node->next;
            }
            */
            (*node) = new ListNode(val%10);
            node = &((*node)->next);
            val = val/10;
        }

        /* don't include in while loop to improve the performance */
        if(val%10)
            (*node) = new ListNode(val%10);

        return head;
    }
};

int main(int argc, char *argv[])
{
	return 0;
}
