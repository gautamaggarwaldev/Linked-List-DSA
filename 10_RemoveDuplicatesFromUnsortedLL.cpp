#include <iostream>
#include <map>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL)
            return NULL;
        Node *curr = head;
        Node *prev = NULL;
        map<int, bool> mp;
        while (curr != NULL)
        {
            if (mp[curr->data])
            {
                prev->next = curr->next;
                curr = prev->next;
            }
            else
            {
                mp[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
int main()
{
    Solution sol;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    Node *result = sol.removeDuplicates(head);
    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}