#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeg(int val) {
    Node* n = new Node{val, head};
    head = n;
}

// Insert at end
void insertEnd(int val) {
    Node* n = new Node{val, NULL};
    if (head == NULL) { 
        head = n; 
        return; 
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

// Insert after a given node (by value)
void insertAfter(int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) { 
        cout << key << " not found\n"; 
        return; 
    }
    Node* n = new Node{val, temp->next};
    temp->next = n;
}

// Display list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    display();              
    insertBeg(5);
    display();              
    insertAfter(20, 25);
    display();              



    return 0;
}