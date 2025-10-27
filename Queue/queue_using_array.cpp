#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Queue using array
Link: https://leetcode.com/problems/implement-queue-using-arrays/
Difficulty: Easy
Time Complexity: O(1) per operation
Space Complexity: O(n)
*/

class Queue {
    vector<int> arr;
    int front, rear, size, capacity;
public:
    Queue(int c): arr(c), front(0), rear(-1), size(0), capacity(c) {}
    void enqueue(int x) {
        if (size == capacity) return;
        rear = (rear+1) % capacity;
        arr[rear] = x; size++;
    }
    void dequeue() {
        if (size==0) return;
        front = (front+1) % capacity;
        size--;
    }
    void display() {
        for(int i=0;i<size;i++) cout<<arr[(front+i)%capacity]<<" ";
        cout<<endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(10); q.enqueue(20); q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
}
