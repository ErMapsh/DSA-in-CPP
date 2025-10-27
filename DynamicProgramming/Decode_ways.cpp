/*
Problem: Decode Ways
Link: https://leetcode.com/problems/decode-ways/
Difficulty: Medium

Approach:
- Use Dynamic Programming (DP) to count the number of valid decoding ways.
- dp[i] represents the number of ways to decode the substring.
- Initialize dp[0] = 1 (empty string) and dp[1] = 1 (if first character is not '0').
- For each position i:
  - If the current character s[i-1] is not '0', add dp[i-1].
  - If the last two characters form a valid number between 10 and 26, add dp[i-2].
- The answer is dp[n], where n is the length of the string.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];

            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};
