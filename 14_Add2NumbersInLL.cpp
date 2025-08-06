#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertAtTail(Node *&head, Node *&tail, int digit)
    {
        Node *temp = new Node(digit);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    Node *add(Node *l1, Node *l2)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int val1 = 0;
            if (l1 != NULL)
            {
                val1 = l1->data;
            }
            int val2 = 0;
            if (l2 != NULL)
            {
                val2 = l2->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (l1 != NULL)
            {
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                l2 = l2->next;
            }
        }
        return ansHead;
    }
    Node *addTwoLists(Node *l1, Node *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);

        Node *ans = add(l1, l2);
        ans = reverse(ans);
        return ans;
    }
};
int main()
{
    Solution sol;
    Node *l1 = new Node(7);
    l1->next = new Node(5);
    l1->next->next = new Node(9);
    l1->next->next->next = new Node(4);
    l1->next->next->next->next = new Node(6);

    Node *l2 = new Node(8);
    l2->next = new Node(4);

    Node *result = sol.addTwoLists(l1, l2);
    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}