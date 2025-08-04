#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Solution
{
public:
    void removeLoop(Node *head)
    {
        if (head == NULL)
            return;
        Node *fast = head;
        Node *slow = head;
        bool flag = false; // no cycle
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                flag = true; // cycle
                break;
            }
        }
        if (flag)
        {
            Node *temp = head;
            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            Node *loopNode = slow;
            Node *t = slow;
            while (t->next != loopNode)
            {
                t = t->next;
            }
            t->next = NULL;
        }
    }
};
int main()
{
    Solution sol;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    sol.removeLoop(head);

    // Print the list to verify the loop is removed
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}