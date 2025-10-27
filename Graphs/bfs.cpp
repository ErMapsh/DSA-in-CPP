#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem: BFS Traversal
Link: https://leetcode.com/problems/breadth-first-search/
Difficulty: Medium
Time Complexity: O(V+E)
Space Complexity: O(V)
*/

void bfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int nbr : adj[node])
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push(nbr);
            }
    }
}

int main() {
    vector<vector<int>> adj = {{1,2}, {0,3}, {0,4}, {1}, {2}};
    cout << "BFS from 0: ";
    bfs(0, adj);
}
