#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // Function to find the root of a node using path compression
    int find(vector<int>& dsuf, int v) {
        if (dsuf[v] == -1)
            return v;
        return dsuf[v] = find(dsuf, dsuf[v]); // Path compression
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> dsuf(n + 1, -1); // Disjoint Set Union-Find array

        for (auto edge : edges) {
            int parent_x = find(dsuf, edge[0]);
            int parent_y = find(dsuf, edge[1]);

            // If both vertices have the same parent, it's a redundant edge
            if (parent_x == parent_y)
                return edge;

            // Union operation: Connect the two components
            dsuf[parent_x] = parent_y;
        }

        return {0, 0}; // This case should not occur in a valid input
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result1 = sol.findRedundantConnection(edges1);
    cout << "Redundant Edge: [" << result1[0] << ", " << result1[1] << "]" << endl; // Expected: [2,3]

    // Test Case 2
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> result2 = sol.findRedundantConnection(edges2);
    cout << "Redundant Edge: [" << result2[0] << ", " << result2[1] << "]" << endl; // Expected: [1,4]

    return 0;
}

