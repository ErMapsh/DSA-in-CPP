/*
Problem: Insert a node at any given position in a Singly Linked List
Difficulty: Easy

---------------------------------------------------------
🧩 Example:
Input:
Linked List: 10 -> 20 -> 30 -> 40
Insert 25 at position 3

Output:
10 -> 20 -> 25 -> 30 -> 40
---------------------------------------------------------
Time Complexity: O(N)
Space Complexity: O(1)
---------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert at a specific position
void insertAtPosition(Node*& head, int val, int pos) {
    Node* newNode = new Node(val);

    if (pos == 1) {  // Insert at start
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display Linked List
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);

    int val = 25, pos = 3;
    insertAtPosition(head, val, pos);

    cout << "After inserting " << val << " at position " << pos << ": ";
    printList(head);

    return 0;
}
