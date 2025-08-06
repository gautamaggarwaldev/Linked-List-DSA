#include <iostream>
#include <map>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};
class Solution
{
public:
    void insertAtTail(Node *&head, Node *&tail, int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node *copyRandomList(Node *head)
    {
        Node *cloneH = NULL;
        Node *cloneT = NULL;

        Node *temp = head;
        while (temp != NULL) // Copying the values to the new list
        {
            insertAtTail(cloneH, cloneT, temp->val);
            temp = temp->next;
        }

        map<Node *, Node *> mp;
        Node *on = head;
        Node *cn = cloneH;
        while (on != NULL && cn != NULL) // Creating a mapping of original nodes to cloned nodes
        {
            mp[on] = cn;
            on = on->next;
            cn = cn->next;
        }
        on = head;
        cn = cloneH;

        while (on != NULL)
        {
            cn->random = mp[on->random]; // Setting the random pointers in the cloned list
            on = on->next;
            cn = cn->next;
        }
        return cloneH;
    }
    // Alternative approach without using a map
    Node *copyRandomList1(Node *head)
    {
        Node *cloneH = NULL;
        Node *cloneT = NULL;

        Node *temp = head;
        // step 1: Create a new list with the same values
        while (temp != NULL)
        {
            insertAtTail(cloneH, cloneT, temp->val);
            temp = temp->next;
        }

        // step 2: Interleave the original and cloned lists
        Node *on = head;
        Node *cn = cloneH;
        while (on != NULL && cn != NULL)
        {
            Node *next = on->next;
            on->next = cn;
            on = next;

            next = cn->next;
            cn->next = on;
            cn = next;
        }

        // step 3: Set the random pointers in the cloned list
        temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                if (temp->random != NULL)
                {
                    temp->next->random = temp->random->next;
                }
                else
                {
                    temp->next->random = NULL;
                }
            }
            temp = temp->next->next;
        }

        // step 4: Restore the original list and separate the cloned list
        on = head;
        cn = cloneH;
        while (on != NULL && cn != NULL)
        {
            on->next = cn->next;
            on = on->next;

            if (on != NULL)
                cn->next = on->next;
            cn = cn->next;
        }
        // step 5: Return the cloned list
        return cloneH;
    }
};
int main()
{
    Solution sol;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Setting random pointers
    head->random = head->next->next;                   // 1 -> 3
    head->next->random = head;                         // 2 -> 1
    head->next->next->random = head->next;             // 3 -> 2
    head->next->next->next->random = head;             // 4 -> 1
    head->next->next->next->next->random = head->next; // 5 -> 2

    Node *clonedList = sol.copyRandomList(head);

    Node *temp = clonedList;
    while (temp != NULL)
    {
        cout << "Value: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }

    return 0;
}