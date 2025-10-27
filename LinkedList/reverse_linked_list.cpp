#include <iostream>
using namespace std;

/*
Problem: Reverse Linked List
Link: https://leetcode.com/problems/reverse-linked-list/
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(1)
*/

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head = reverseList(head);
    for (Node* temp = head; temp; temp = temp->next)
        cout << temp->data << " ";
}
