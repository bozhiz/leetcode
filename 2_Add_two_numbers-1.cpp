#include "tools.hpp"

using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int val = 0;
        ListNode *head = NULL;
        ListNode **node = &head;

        while (l1 || l2)
        {
            if (l1)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
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
            (*node) = new ListNode(val % 10);
            node = &((*node)->next);
            val = val / 10;
        }

        /* don't include in while loop to improve the performance */
        if (val % 10)
            (*node) = new ListNode(val % 10);

        return head;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v1 = {2, 7, 1, 5};
    vector<int> v2 = {8, 9, 9, 8, 9};
    ListNode *l1 = ListCreate(v1);
    ListNode *l2 = ListCreate(v2);

    unique_ptr<Solution> pS(new Solution());

    ListNode *l3 = pS->addTwoNumbers(l1, l2);
    ListPrint(l1);
    ListPrint(l2);
    ListPrint(l3);

    ListDestroy(l1);
    ListDestroy(l2);
    ListDestroy(l3);
    return 0;
}
