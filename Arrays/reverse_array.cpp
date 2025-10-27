#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Reverse an Array
Link: https://leetcode.com/problems/reverse-string/
Difficulty: Easy
Approach: Two-pointer technique
Time Complexity: O(n)
Space Complexity: O(1)
*/

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }
    for (int x : arr) cout << x << " ";
    cout << endl;
}
