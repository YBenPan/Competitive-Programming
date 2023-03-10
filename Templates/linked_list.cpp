#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class LinkedList {
    Node *head;

    public: 

        LinkedList() {
            head = NULL;
        }

        void insertNode(int);

        void insertAtPos(int, int);

        void printList();

        void deleteNode(int);

        void reverseList();
};

void LinkedList::insertNode(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

// 1-indexed linked list
void LinkedList::insertAtPos(int pos, int val) {
    if (pos <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* ptr = head;
    
    // Move to pos 
    for (int i = 1; i < pos - 1; i++) {
        if (ptr->next == nullptr) {
            cout << "Pos argument out of bound!" << endl;
            return;
        }
        ptr = ptr->next;
    }
    
    // Add new node
    if (ptr->next == nullptr) {
        ptr->next = newNode;
    }
    else {
        Node* ptr1 = ptr->next;
        ptr->next = newNode;
        newNode->next = ptr1;
    }
}

void LinkedList::printList() {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->data << " -> ";    
        ptr = ptr->next;
    }
    cout << "END" << endl;
}

void LinkedList::deleteNode(int pos) {
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    Node* ptr = head;
    if (pos == 1) {
        head = ptr->next;
        delete ptr;
        return;
    }
    for (int i = 1; i < pos - 1; i++) {
        if (ptr->next == nullptr) {
            cout << "Pos argument out of bound!" << endl;
            return;
        }
        ptr = ptr->next;
    }
    Node* deleted_ptr = ptr->next;
    ptr->next = deleted_ptr->next;
    delete deleted_ptr;
}

void LinkedList::reverseList() {
    Node *ptr = head, *prev = NULL, *next = NULL;
    while (ptr != nullptr) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
}

int main() {
    LinkedList ll;
    ll.insertNode(5);
    ll.insertAtPos(1, 10);
    ll.printList();
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(3);
    ll.printList();
    ll.reverseList();
    ll.printList();
    ll.deleteNode(5);
    ll.deleteNode(1);
    ll.deleteNode(1);
    ll.printList();

    return 0;
}