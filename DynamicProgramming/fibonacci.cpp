#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Fibonacci Number
Link: https://leetcode.com/problems/fibonacci-number/
Difficulty: Easy
Approach: DP tabulation
Time Complexity: O(n)
Space Complexity: O(n)
*/

int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
}
