#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    void insertAtTail(Node *&tail, Node *temp)
    {
        tail->next = temp;
        tail = temp;
    }
    Node *segregate(Node *head)
    {
        // code here
        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;
        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;
        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        Node *temp = head;
        while (temp != NULL)
        {
            int val = temp->data;
            if (val == 0)
            {
                insertAtTail(zeroTail, temp);
            }
            else if (val == 1)
            {
                insertAtTail(oneTail, temp);
            }
            else
            {
                insertAtTail(twoTail, temp);
            }
            temp = temp->next;
        }

        // merge list

        if (oneHead->next != NULL)
        {
            zeroTail->next = oneHead->next;
        }
        else
        {
            zeroTail->next = twoHead->next;
        }
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        return zeroHead->next;
    }
};
int main()
{
    Solution sol;
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    Node *result = sol.segregate(head);
    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}