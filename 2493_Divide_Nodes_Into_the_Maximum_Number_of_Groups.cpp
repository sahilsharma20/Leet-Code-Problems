#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    // Function to check if a connected component is bipartite using BFS
    bool isComponentBipartite(vector<vector<int>>& adj, vector<int>& state, int start) {
        queue<int> q;
        q.push(start);
        state[start] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nbr : adj[curr]) {
                if (state[nbr] == 0) {
                    state[nbr] = (-1) * state[curr]; // Assign opposite color
                    q.push(nbr);
                } else if (state[nbr] == state[curr]) {
                    return false; // Conflict detected, not bipartite
                }
            }
        }
        return true;
    }

    // Check if the entire graph is bipartite
    bool checkBipartiteGraph(vector<vector<int>>& adj, int n) {
        vector<int> state(n + 1, 0); // 0 = unvisited, 1 = color1, -1 = color2
        for (int i = 1; i <= n; ++i) {
            if (state[i] == 0 && !isComponentBipartite(adj, state, i))
                return false;
        }
        return true;
    }

    // BFS to count levels in a component
    int countLevels(vector<vector<int>>& adj, int n, int source) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        int levels = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                for (int nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            levels++;
        }
        return levels;
    }

    // BFS to find the max level distance in a connected component
    int findMaxLevelsBFS(vector<int>& max_distance, vector<vector<int>>& adj, vector<bool>& visited, int source) {
        queue<int> q;
        q.push(source);
        visited[source] = true;

        int max_levels = -1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            max_levels = max(max_levels, max_distance[curr]);
            for (int nbr : adj[curr]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return max_levels;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Step-1: Construct adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step-2: Check if the graph is bipartite
        if (!checkBipartiteGraph(adj, n))
            return -1;

        // Step-3: Compute max distance for each node using BFS
        vector<int> max_distance(n + 1);
        for (int i = 1; i <= n; ++i)
            max_distance[i] = countLevels(adj, n, i);

        // Step-4: Find the max level count per component
        vector<bool> visited(n + 1, false);
        int total_levels = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                total_levels += findMaxLevelsBFS(max_distance, adj, visited, i);
        }

        return total_levels;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int n1 = 6;
    vector<vector<int>> edges1 = {{1,2}, {1,4}, {1,5}, {2,6}, {2,3}, {4,6}};
    cout << "Output: " << sol.magnificentSets(n1, edges1) << endl; // Expected Output: 4

    // Test Case 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{1,2}, {2,3}, {3,1}};
    cout << "Output: " << sol.magnificentSets(n2, edges2) << endl; // Expected Output: -1

    return 0;
}

