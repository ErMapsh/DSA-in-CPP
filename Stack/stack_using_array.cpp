#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Implement Stack using Array
Link: https://leetcode.com/problems/implement-stack-using-arrays/
Difficulty: Easy
Time Complexity: O(1) per operation
Space Complexity: O(n)
*/

class Stack{
    vector<int> arr;
    int top=-1, capacity;
public:
    Stack(int c): capacity(c), arr(c){}
    void push(int x){ if(top<capacity-1) arr[++top]=x;}
    void pop(){ if(top>=0) top--;}
    void display(){ for(int i=0;i<=top;i++) cout<<arr[i]<<" "; cout<<endl;}
};

int main(){
    Stack s(5);
    s.push(10); s.push(20); s.push(30);
    s.display();
    s.pop();
    s.display();
}
