#include "tools.hpp"

using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;
        ListNode *tmp;
        stack<int> l1S;
        stack<int> l2S;
        int sum = 0;

        for (tmp = l1; tmp != nullptr; tmp = tmp->next)
            l1S.push(tmp->val);

        for (tmp = l2; tmp != nullptr; tmp = tmp->next)
            l2S.push(tmp->val);

        while (!l1S.empty() || !l2S.empty() || sum != 0)
        {
            if (!l1S.empty())
            {
                sum += l1S.top();
                l1S.pop();
            }

            if (!l2S.empty())
            {
                sum += l2S.top();
                l2S.pop();
            }

            tmp = new ListNode(sum % 10);
            tmp->next = dummy.next;
            dummy.next = tmp;
            sum /= 10;
        }

        return dummy.next;
    }
};

int main(int argc, char *argv[])
{
    Solution *s = new Solution();

    vector<int> v1 = {7, 2, 4, 3};
    vector<int> v2 = {5, 6, 4};
    ListNode *l1 = ListCreate(v1);
    ListNode *l2 = ListCreate(v2);

    ListPrint(s->addTwoNumbers(l1, l2));

    delete pS;
    return 0;
}
