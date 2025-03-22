#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        // Construct adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int completeComponents = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_set<int> nodes;
                bool isComplete = true;
                
                // Perform DFS to find all nodes in this component
                dfs(i, adj, visited, nodes);
                
                // Check if this component forms a complete graph
                for (int node : nodes) {
                    if (adj[node].size() != nodes.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }
                
                if (isComplete) completeComponents++;
            }
        }
        
        return completeComponents;
    }
    
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, unordered_set<int>& nodes) {
        visited[node] = true;
        nodes.insert(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodes);
            }
        }
    }
};
