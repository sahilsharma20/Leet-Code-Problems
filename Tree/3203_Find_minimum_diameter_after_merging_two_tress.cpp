#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    // Helper function to calculate the diameter of a tree
    int diameter(unordered_map<int, vector<int>>& adj, int n) {
        // Step 1: Find the farthest node from an arbitrary node (e.g., node 0)
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int last; // Last node encountered in BFS

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                last = q.front();
                q.pop();
                for (int neighbor : adj[last]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

        // Step 2: Find the farthest node from 'last' to calculate diameter
        q.push(last);
        int hops = 0;
        vector<bool> vis(n, false);
        vis[last] = true;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            hops++; // Increment hops for each level of BFS
        }

        return hops - 1; // Diameter is one less than the total hops
    }

    // Function to find the diameter of a graph given its edges
    int findDiameter(vector<vector<int>>& edges) {
        if (edges.empty()) return 0; // No edges, diameter is 0

        // Create adjacency list from the edges
        unordered_map<int, vector<int>> adj;
        unordered_set<int> nodes;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }

        return diameter(adj, nodes.size());
    }

public:
    // Main function to compute the minimum diameter after merging two graphs
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Find diameters of the two graphs
        int dia1 = findDiameter(edges1);
        int dia2 = findDiameter(edges2);

        // Calculate the radii of the two graphs
        int radius1 = (dia1 + 1) / 2;
        int radius2 = (dia2 + 1) / 2;

        // Calculate the combined diameter after merging
        int combinedDiameter = 1 + radius1 + radius2;

        // Return the maximum of the combined diameter and the original diameters
        return max(combinedDiameter, max(dia1, dia2));
    }
};

// Example usage
int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}};
    vector<vector<int>> edges2 = {{0, 1}};
    int result1 = solution.minimumDiameterAfterMerge(edges1, edges2);
    cout << "Minimum Diameter After Merge (Test Case 1): " << result1 << endl;

    // Test case 2
    vector<vector<int>> edges1_2 = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
    vector<vector<int>> edges2_2 = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
    int result2 = solution.minimumDiameterAfterMerge(edges1_2, edges2_2);
    cout << "Minimum Diameter After Merge (Test Case 2): " << result2 << endl;

    return 0;
}

