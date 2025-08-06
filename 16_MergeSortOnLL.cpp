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
    Node *middle(Node *head)
    {
        if (!head)
            return nullptr;
        Node *slow = head, *fast = head->next;
        while (fast && fast->next)
        { // Slightly simpler and more robust loop
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merges two sorted linked lists
    Node *merge(Node *list1, Node *list2)
    {
        Node dummy(0); // stack variable, no leak
        Node *tail = &dummy;
        while (list1 && list2)
        {
            if (list1->data <= list2->data)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }

    Node *mergeSort(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *mid = middle(head);
        Node *right = mid->next;
        mid->next = nullptr; // split the list into two halves

        Node *left = mergeSort(head);
        right = mergeSort(right);

        return merge(left, right);
    }
};

int main()
{
    Solution sol;
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    Node *sortedHead = sol.mergeSort(head);

    Node *temp = sortedHead;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
