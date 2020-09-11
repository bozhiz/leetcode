#include "tools.hpp"

using namespace std;

class Solution
{
public:
    ListNode *insertNodeAtPosition(ListNode *head, int data, int position)
    {
        ListNode *node = head, *newNode = nullptr;
        int i = 0;

        if (head == nullptr && position != 0)
            return head;

        while (i < position - 1 && node != nullptr)
        {
            node = node->next;
            i++;
        }

        if (i < position - 1)
            return head;

        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->val = data;

        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = node->next;
            node->next = newNode;
        }
        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution *pS = new Solution();

    vector<int> v1 = {16, 3, 7};
    ListNode *l1 = ListCreate(v1);
    pS->insertNodeAtPosition(l1, 1, 2);
    ListPrint(l1);
    ListDestroy(l1);

    delete pS;
    return 0;
}
