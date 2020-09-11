// C++ program to reverse a linked list using two pointers.
#include "tools.hpp"

/* Function to reverse the linked list using 2 pointers */
void reverse(struct ListNode **head_ref)
{
    struct ListNode *current = *head_ref;
    struct ListNode *next;
    while (current->next != NULL)
    {
        next = current->next;
        current->next = next->next;
        next->next = (*head_ref);
        *head_ref = next;
    }
}

/* Driver program to test above function*/
int main()
{
    vector<int> v({20, 4, 15, 85});
    struct ListNode *head = ListCreate(v);

    printf("Given linked list\n");
    ListPrint(head);
    reverse(&head);
    printf("Reversed Linked list\n");
    ListPrint(head);

    //Should delete list here
    ListDestroy(head);
    return 0;
}
