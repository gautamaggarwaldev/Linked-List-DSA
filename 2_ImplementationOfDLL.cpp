# include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

int CalculateDLLL(Node* &head) {
    Node* temp = head;
    int len=0;
    while(temp!=NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void PrintDLL(Node* &head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertionAtHead(Node* &head, int val) {
    Node* temp = new Node(val);
    Node* temp1 = head;
    temp->next = temp1;
    temp1->prev = temp;
    temp->prev = NULL;
    head = temp;
    return;

}

void InsertionAtEnd(Node* &head, int val) {
    Node* temp = new Node(val);
    Node* temp1 = head;
    while(temp1->next!=NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
    temp->next = NULL;
}

void InsertionAtMiddle(Node* &head, int val) {
    Node* temp = new Node(val);
    Node* temp1 = head;
    int len = CalculateDLLL(temp1);
    if(len%2==0) { //len is even
        int i = (len/2)-1;
        while(i--) {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->next = temp;
        temp->prev = temp1;

    }
    else { //len is odd
        int i = ((len+1)/2)-1;
        while(i--) {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->next = temp;
        temp->prev = temp1;
    }
}

void InsertionAtPosition(Node* &head, int val, int pos) {
    Node* temp = new Node(val);
    Node* temp1 = head;
    if(pos > CalculateDLLL(head) || pos <=0) {
        return;
    }
    if(pos==1) {
        temp->next = temp1;
        temp1->prev = temp;
        temp->prev = NULL;
        head = temp;
        return;
    }
    int i=pos-2;
    while(i--) {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next->prev = temp;
    temp->prev = temp1;
    temp1->next = temp;
}


void DeletionAtHead(Node* &head) {
    Node* temp = head->next;
    temp->prev = NULL;
    head = head->next;
}

void DeletionAtEnd(Node* head) {
    Node* temp = head;
    Node* temp1 = head->next;
    int len = CalculateDLLL(head);
    int i = len-2;
    while(i--) {
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp->next = NULL;
    temp1->prev = NULL;
}

void DeletionAtPosition(Node* head, int pos) {
    Node* temp = head;
    Node* temp1 = head->next;
    if(pos > CalculateDLLL(head) || pos<=0 || head==NULL) {
        return;
    }
    int i = pos-2;
    while(i--) {
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next->prev = temp;
    temp1->next = NULL;
    temp1->prev = NULL;
}

void DeletionByValue(Node* &head, int val) {
    Node* temp = head;
    Node* temp2 = head;
    int cnt = 0;
    while (val != temp2->val)
    {
        temp2 = temp2->next;
        cnt++;
    }
    int i = cnt-1;
    while(i--) {
        temp = temp->next;
    }
    temp->next = temp2->next;
    temp2->next->prev = temp;
    temp2->next = NULL;
    temp2->prev = NULL;

}



int main() {
    Node* head = new Node(10);

    InsertionAtHead(head,20);
    InsertionAtEnd(head,30);
    InsertionAtEnd(head,40);
    PrintDLL(head);
    InsertionAtMiddle(head, 50);
    PrintDLL(head);
    InsertionAtMiddle(head, 60);
    PrintDLL(head);
    InsertionAtPosition(head,70,3);
    PrintDLL(head);
    InsertionAtPosition(head,80,1);
    PrintDLL(head);
    DeletionAtHead(head);
    PrintDLL(head);
    DeletionAtEnd(head);
    PrintDLL(head);
    DeletionAtPosition(head, 2);
    PrintDLL(head);
    DeletionByValue(head, 50);
    PrintDLL(head);
}