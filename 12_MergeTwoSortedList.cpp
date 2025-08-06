#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        if (list2->val < list1->val)
        {
            swap(list1, list2);
        }
        ListNode *curr1 = list1;
        ListNode *next1 = curr1->next;
        ListNode *curr2 = list2;
        ListNode *next2 = curr2->next;
        while (next1 != NULL && curr2 != NULL)
        {
            if (curr2->val >= curr1->val && curr2->val <= next1->val)
            {
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                curr1 = curr1->next;
                next1 = next1->next;
            }
        }
        if (next1 == NULL) // list 1 is exhausted
        {
            curr1->next = curr2;
        }
        return list1;
    }
};
int main()
{
    Solution sol;
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *result = sol.mergeTwoLists(list1, list2);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}