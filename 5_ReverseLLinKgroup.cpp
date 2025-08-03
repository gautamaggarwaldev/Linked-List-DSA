#include <iostream>
#include <vector>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
            return head;
        ListNode *node = head;
        int count = 0;
        while (node != NULL && count < k)
        {
            node = node->next;
            count++;
        }

        if (count < k)
            return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};
int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2; // Change k to test different group sizes
    ListNode *reversedHead = sol.reverseKGroup(head, k);

    ListNode *temp = reversedHead;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}