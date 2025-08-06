#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

class Solution
{
public:
    Node *merge(Node *a, Node *b)
    {
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        Node *res;
        if (a->data < b->data) // Compare the data of the nodes
        {
            res = a;
            res->bottom = merge(a->bottom, b); // Recursively merge the bottom lists
        }
        else
        {
            res = b;
            res->bottom = merge(a, b->bottom); // Recursively merge the bottom lists
        }
        res->next = NULL; // Ensure the next pointer is NULL as we are merging bottom lists 
        // and not the next pointers of the original lists.
        return res;
    }
    Node *flatten(Node *root)
    {
        if (root == NULL || root->next == NULL)
            return root;
        root->next = flatten(root->next); // Flatten the next list
        root = merge(root, root->next); // Merge the current list with the flattened next list
        // Now root is the head of the merged list
        return root;
    }
};
int main()
{
    Solution sol;
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Node *flattenedList = sol.flatten(head);

    // Print the flattened list
    Node *temp = flattenedList;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;

    return 0;
}