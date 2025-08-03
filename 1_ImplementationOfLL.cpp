#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int val;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void InsertionAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void InsertionAtEnd(Node *&head, int val)
{
    Node *temp = new Node(val);
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

int calculateLLL(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void InsertionAtMiddle(Node *&head, int val)
{
    Node *temp = new Node(val);
    Node *temp1 = head;
    int s = calculateLLL(temp1);
    if (s % 2 == 0)
    { // length is even
        int i = (s / 2) - 1;
        while (i--)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
    else
    { // length is odd
        int i = ((s + 1) / 2) - 1;
        while (i--)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

void InsertAtPosition(Node *&head, int val, int pos)
{
    Node *temp = new Node(val);
    Node *temp1 = head;
    if (pos > calculateLLL(temp1) || pos <= 0)
    {
        return;
    }
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    int i = pos - 2;
    while (i--)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void DeleteAtEnd(Node *&head)
{
    Node *temp = head;
    int len = calculateLLL(head);
    int i = len - 2;
    while (i--)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void DeleteAtHead(Node *&head)
{
    Node *temp = head->next;
    head = head->next;
}

void DeleteAtPosition(Node *&head, int pos)
{
    Node *temp = head;
    Node *temp1 = head->next;
    if (pos == 1)
    {
        temp = head->next;
        head = head->next;
        return;
    }
    if (pos > calculateLLL(head) || pos <= 0)
    {
        return;
    }
    int i = pos - 2;
    while (i--)
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = NULL;
}

void DeleteByVal(Node *&head, int x)
{
    Node *temp = head;
    Node *temp1 = head;
    if (x == head->val)
    {
        temp = head->next;
        head = head->next;
        return;
    }
    int cnt = 0;
    while (x != temp->val)
    {
        temp = temp->next;
        cnt++;
    }
    int i = cnt - 1;
    while (i--)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp->next;
    temp->next = NULL;
}

void PrintLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(20);

    InsertionAtHead(head, 10);
    InsertionAtEnd(head, 30);
    InsertionAtEnd(head, 40);
    InsertionAtMiddle(head, 50);
    InsertionAtMiddle(head, 60);
    InsertionAtMiddle(head, 70);
    PrintLL(head);
    InsertAtPosition(head, 80, 3);
    InsertAtPosition(head, 90, 1);
    InsertAtPosition(head, 100, 7);
    PrintLL(head);
    DeleteAtEnd(head);
    PrintLL(head);
    DeleteAtHead(head);
    PrintLL(head);
    DeleteAtPosition(head, 4);
    PrintLL(head);
    DeleteByVal(head, 100);
    PrintLL(head);
}
