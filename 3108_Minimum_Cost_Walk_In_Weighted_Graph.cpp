#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> component(n, -1);
        vector<int> minAnd(n, INT_MAX);
        int compID = 0;

        // Step 1: Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Step 2: Find connected components and compute minimum AND cost
        auto dfs = [&](int node, int id, int& minCost, auto&& dfs_ref) -> void {
            component[node] = id;
            for (auto &[neighbor, weight] : graph[node]) {
                minCost &= weight; // Track the minimum AND cost
                if (component[neighbor] == -1) {
                    dfs_ref(neighbor, id, minCost, dfs_ref);
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            if (component[i] == -1) { // New component
                int minCost = INT_MAX;
                dfs(i, compID, minCost, dfs);
                minAnd[compID] = minCost;
                compID++;
            }
        }

        // Step 3: Process queries
        vector<int> answer;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (component[s] != component[t]) {
                answer.push_back(-1);
            } else {
                answer.push_back(minAnd[component[s]]);
            }
        }

        return answer;
    }
};

// Driver Code
int main() {
    Solution sol;
    
    int n = 5;
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> query = {{0,3},{3,4}};

    vector<int> result = sol.minimumCost(n, edges, query);
    
    cout << "Output: ";
    for (int ans : result) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
