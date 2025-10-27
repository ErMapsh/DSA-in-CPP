#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Binary Search
Link: https://leetcode.com/problems/binary-search/
Difficulty: Easy
Time Complexity: O(log n)
Space Complexity: O(1)
*/

int binarySearch(vector<int>& arr, int target) {
    int l=0, r=arr.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main() {
    vector<int> arr = {1,3,5,7,9};
    int target=7;
    cout << "Index of "<<target<<": "<<binarySearch(arr,target);
}
