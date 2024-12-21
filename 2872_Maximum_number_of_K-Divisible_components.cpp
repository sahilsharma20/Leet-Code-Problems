#include <iostream>
#include <vector>
using namespace std;

/*
Problem Explanation:
Given a tree with `n` nodes, represented as an undirected graph with `edges`, each node has a value from the `values` array. 
The task is to determine the maximum number of connected components that can be formed such that the sum of values in each component is divisible by `k`.
The solution uses Depth-First Search (DFS) to traverse the tree, calculate the sum of values for each component, and check divisibility by `k`.
*/

class Solution {
    // Helper function to perform DFS and calculate the sum of values
    int dfs(vector<vector<int>>& adj, vector<int>& values, int& k, int& count, int curr, int parent = -1) {
        long long sum = values[curr]; // Initialize sum with the current node's value
        for (int nbr : adj[curr]) {  // Traverse all adjacent nodes
            if (nbr != parent)       // Avoid going back to the parent node
                sum += dfs(adj, values, k, count, nbr, curr);
        }
        sum %= k; // Compute sum modulo k
        if (sum == 0) // If the sum is divisible by k, increase the component count
            count++;
        return sum;
    }

public:
    // Function to calculate the maximum number of k-divisible components
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n); // Adjacency list representation of the tree
        for (auto edge : edges) {  // Build the adjacency list
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count = 0; // Initialize the count of k-divisible components
        dfs(adj, values, k, count, 0); // Start DFS from the root (node 0)
        return count; // Return the final count
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Example 1
    int n1 = 5;
    vector<vector<int>> edges1 = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> values1 = {1, 8, 1, 4, 4};
    int k1 = 6;

    cout << "Example 1 - Maximum K-Divisible Components: " 
         << sol.maxKDivisibleComponents(n1, edges1, values1, k1) << endl;

    // Example 2
    int n2 = 7;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    vector<int> values2 = {3, 0, 6, 1, 5, 2, 1};
    int k2 = 3;

    cout << "Example 2 - Maximum K-Divisible Components: " 
         << sol.maxKDivisibleComponents(n2, edges2, values2, k2) << endl;

    return 0;
}

