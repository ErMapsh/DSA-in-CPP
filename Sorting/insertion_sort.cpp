#include <iostream>
using namespace std;

/*
Problem: Insertion Sort
Link: https://leetcode.com/problems/sort-an-array/
Difficulty: Easy
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i], j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]={12,11,13,5,6}, n=5;
    insertionSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
