#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
Problem: Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(1)
*/

bool isPalindrome(string s){
    int i=0, j=s.size()-1;
    while(i<j){
        while(i<j && !isalnum(s[i])) i++;
        while(i<j && !isalnum(s[j])) j--;
        if(tolower(s[i])!=tolower(s[j])) return false;
        i++; j--;
    }
    return true;
}

int main(){
    string s="A man, a plan, a canal: Panama";
    cout<<(isPalindrome(s)?"Palindrome":"Not Palindrome");
}
