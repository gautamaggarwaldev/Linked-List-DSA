#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *t1 = head;
        ListNode *t2 = head->next;

        while (t2 != NULL)
        {
            if (t1->val == t2->val)
            {
                t1->next = t2->next;
                t2 = t1->next;
            }
            else
            {
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        return head;
    }
};
int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    ListNode *result = sol.deleteDuplicates(head);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}