#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    vector<bool> safe_nodes;
    
    bool checkSafeState(vector<vector<int>>& graph, vector<int>& visited, int curr) {
        visited[curr] = 1; // Mark as visiting
        bool is_safe = true;

        for (int nbr : graph[curr]) {
            if (visited[nbr] == 0) { // Unvisited neighbor
                is_safe &= checkSafeState(graph, visited, nbr);
            } else if (visited[nbr] == 1) { // Back edge (cycle)
                return safe_nodes[curr] = false;
            } else if (visited[nbr] == 2) { // Processed neighbor
                is_safe &= safe_nodes[nbr];
            }
        }

        visited[curr] = 2; // Mark as processed
        return safe_nodes[curr] = is_safe;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        safe_nodes = vector<bool>(n, true); // Assume all nodes are safe initially
        vector<int> visited(n, 0);         // 0: Unvisited, 1: Visiting, 2: Processed

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                checkSafeState(graph, visited, i);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (safe_nodes[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> graph1 = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> res1 = sol.eventualSafeNodes(graph1);
    cout << "Output for graph1: ";
    for (int node : res1) cout << node << " ";
    cout << endl; // Expected: 2 4 5 6

    // Test Case 2
    vector<vector<int>> graph2 = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    vector<int> res2 = sol.eventualSafeNodes(graph2);
    cout << "Output for graph2: ";
    for (int node : res2) cout << node << " ";
    cout << endl; // Expected: 4

    return 0;
}

