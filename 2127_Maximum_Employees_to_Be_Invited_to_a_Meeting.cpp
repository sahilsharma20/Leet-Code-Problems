#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    // Mark all non-cyclic nodes using Kahn's Topological Sort
    int kahnsTopologicalSort(vector<int>& adj, vector<int>& indegree, vector<bool>& visited, int source) {
        queue<int> q;
        q.push(source);
        int last_node;
        
        // Process the nodes in the queue
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            last_node = curr;
            
            // Find the neighbors and reduce their indegree
            int nbr = adj[curr];
            indegree[nbr] -= 1;
            
            // If a neighbor has no incoming edges, add it to the queue
            if (indegree[nbr] == 0 && !visited[nbr]) {
                q.push(nbr);
            }
        }
        return adj[last_node]; // Return the last node in the topological order
    }

    // Find the maximum tail-length (longest distance from a node to a cycle)
    int maxDepthBFS(vector<vector<int>>& adj, vector<bool>& orig_visited, int n, int source, int avoid) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        visited[avoid] = true; // Avoid the cycle node
        
        int levels = 0;
        
        // Perform BFS to calculate the maximum tail length
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                orig_visited[curr] = true;
                
                // Explore neighbors
                for (int nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            levels++;
        }
        return levels; // Return the maximum tail length
    }

    // Find the cycle length from a source node
    int bfs(vector<int>& adj, vector<bool>& visited, int source) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        int count = 0;
        
        // Perform BFS to count the cycle length
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // If the adjacent node hasn't been visited, add it to the queue
            if (!visited[adj[curr]]) {
                visited[adj[curr]] = true;
                q.push(adj[curr]);
            }
            count++;
        }
        return count; // Return the cycle size
    }

public:
    int maximumInvitations(vector<int>& adj) {
        int n = adj.size();
        vector<vector<int>> reverse_adj(n);
        vector<int> indegree(n, 0); // For Kahn's Algo (Topological sort)
        
        // Step-1: Build the reverse adjacency list and calculate indegrees
        for (int i = 0; i < n; ++i) {
            reverse_adj[adj[i]].push_back(i);
            indegree[adj[i]]++;
        }
        
        // Step-2: Mark nodes that are not part of any cycle using topological sort
        int tot_tail_len = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0 && !visited[i]) {
                int node = kahnsTopologicalSort(adj, indegree, visited, i);
                
                // Check if the node and its neighbor form a cycle of length 2
                if (adj[adj[node]] == node) {
                    int len_tail = maxDepthBFS(reverse_adj, visited, n, node, adj[node]) - 1;
                    tot_tail_len += len_tail; // Add all cycles of length 2 with tails
                    visited[node] = false; // Reset visited for next cycle
                }
            }
        }
        
        // Step-3: For cycles larger than 2, track the maximum size
        int two_size_cycles = 0;
        int max_cycle_size = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int cycle_size = bfs(adj, visited, i);
                if (cycle_size == 2) {
                    two_size_cycles++;
                } else {
                    max_cycle_size = max(max_cycle_size, cycle_size);
                }
            }
        }
        
        // Step-4: Return the maximum of the two cases: 
        // Total length from 2-size cycles + max length from larger cycles
        int cyclesize_2 = tot_tail_len + 2 * two_size_cycles;
        return max(cyclesize_2, max_cycle_size);
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> favorite1 = {2, 2, 1, 2};
    vector<int> favorite2 = {1, 2, 0};
    vector<int> favorite3 = {3, 0, 1, 4, 1};
    
    // Print the output for each test case
    cout << sol.maximumInvitations(favorite1) << endl; // Expected Output: 3
    cout << sol.maximumInvitations(favorite2) << endl; // Expected Output: 3
    cout << sol.maximumInvitations(favorite3) << endl; // Expected Output: 4
    return 0;
}

