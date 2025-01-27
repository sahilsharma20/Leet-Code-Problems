#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    #define INT_MAX 10000
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Initialize the distance matrix
        vector<vector<int>> dist(numCourses, vector<int>(numCourses, INT_MAX));

        // Set distance to self as 0
        for (int i = 0; i < numCourses; ++i)
            dist[i][i] = 0;

        // Populate the adjacency matrix based on prerequisites
        for (auto& edge : prerequisites) {
            dist[edge[0]][edge[1]] = 1; // Direct prerequisite
        }

        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        // Process each query
        vector<bool> ans;
        for (auto& query : queries) {
            // Check if there's a path between query[0] and query[1]
            if (dist[query[0]][query[1]] < INT_MAX)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<vector<int>> queries1 = {{0, 1}, {1, 0}};
    vector<bool> res1 = sol.checkIfPrerequisite(numCourses1, prerequisites1, queries1);
    cout << "Output for Test Case 1: ";
    for (bool ans : res1) cout << (ans ? "true" : "false") << " ";
    cout << endl; // Expected: false true

    // Test Case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {};
    vector<vector<int>> queries2 = {{1, 0}, {0, 1}};
    vector<bool> res2 = sol.checkIfPrerequisite(numCourses2, prerequisites2, queries2);
    cout << "Output for Test Case 2: ";
    for (bool ans : res2) cout << (ans ? "true" : "false") << " ";
    cout << endl; // Expected: false false

    // Test Case 3
    int numCourses3 = 3;
    vector<vector<int>> prerequisites3 = {{1, 2}, {1, 0}, {2, 0}};
    vector<vector<int>> queries3 = {{1, 0}, {1, 2}};
    vector<bool> res3 = sol.checkIfPrerequisite(numCourses3, prerequisites3, queries3);
    cout << "Output for Test Case 3: ";
    for (bool ans : res3) cout << (ans ? "true" : "false") << " ";
    cout << endl; // Expected: true true

    return 0;
}

