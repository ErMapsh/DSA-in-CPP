/*
Problem: Allocate Minimum Number of Pages
Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
Difficulty: Medium

---------------------------------------------------------
📘 Problem Statement:
---------------------------------------------------------
You are given:
- An array `arr[]` of size `n` representing the number of pages in each book.
- `m` students.

Each student must get at least one book, and every book can be allocated to exactly one student.
Books are arranged in order and must be allocated in sequence.

🎯 Task:
Distribute books in such a way that the **maximum number of pages assigned to a student is minimized.**

---------------------------------------------------------
📊 Example:
---------------------------------------------------------
Input:
arr = [10, 20, 30, 40, 50], n = 5, m = 2

Possible allocations:
1. [10,20,30] and [40,50] → max pages = 90  
2. [10,20] and [30,40,50] → max pages = 120  
3. [10,20,30,40] and [50] → max pages = 100  

✅ Minimum possible maximum pages = 90

Output: 90
*/


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*---------------------------------------------------------
🧠 BRUTE FORCE APPROACH
-----------------------------------------------------------
Approach:
1. Try all possible ways to divide the books among students.
2. For each division, calculate the maximum pages a student gets.
3. Return the minimum among all such maximums.

⚠️ This approach has exponential complexity (O(n^m)), 
so it’s not feasible for large inputs.
Used only for conceptual understanding.

Example:
arr = [10, 20, 30], m = 2
Possible divisions:
 - [10] | [20,30]  → max = 50
 - [10,20] | [30]  → max = 30
Minimum = 30 ✅
-----------------------------------------------------------*/

// (Brute force omitted in practice due to high complexity)





/*---------------------------------------------------------
⚡ OPTIMAL APPROACH — Binary Search on Answer
-----------------------------------------------------------
Intuition:
We need to minimize the **maximum pages** a student can get.
This can be done by **binary searching** the possible range of answers.

Range:
- Minimum possible = max(arr) (a student must at least take the thickest book)
- Maximum possible = sum(arr) (if one student takes all books)

Steps:
1. Use binary search on the range [max(arr), sum(arr)].
2. For a mid value, check if it is possible to allocate books
   so that no student gets more than 'mid' pages.
3. If possible → search in left half (try smaller maximum)
   If not → search in right half (increase maximum)

Helper Function:
`isPossible()` checks if a given max page limit (mid) works with m students.

-----------------------------------------------------------
Time Complexity: O(n * log(sum(arr) - max(arr)))
Space Complexity: O(1)
-----------------------------------------------------------*/


bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false; // Single book exceeds mid

        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];  // Allocate to current student
        } else {
            // Allocate to next student
            studentCount++;
            if (studentCount > m) return false;
            pageSum = arr[i];
        }
    }

    return true;
}


int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1; // Not enough books

    int sum = accumulate(arr.begin(), arr.end(), 0);
    int s = 0, e = sum, ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;    // Possible → minimize further
            e = mid - 1;
        } else {
            s = mid + 1;  // Not possible → increase limit
        }
    }

    return ans;
}


/*---------------------------------------------------------
🔍 Example Test Run
-----------------------------------------------------------
Input:
arr = [10, 20, 30, 40, 50], n = 5, m = 2

Binary Search Steps:
- Range: [50, 150]
- mid = 100 → possible ✅ → move left
- mid = 75  → not possible ❌ → move right
- mid = 90  → possible ✅ → move left
- mid = 85  → not possible ❌
✅ Final Answer = 90

Output: 90
-----------------------------------------------------------*/


int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    int m = 2;

    cout << "Books: ";
    for (int pages : arr) cout << pages << " ";
    cout << "\nStudents: " << m << endl;

    cout << "Minimum possible maximum pages: " << findPages(arr, n, m) << endl;
    return 0;
}
