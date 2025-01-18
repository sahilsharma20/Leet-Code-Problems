#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    #define pip pair<int, pair<int, int>>
    
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Min-heap to store (cost, (row, col))
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        minHeap.push({0, {0, 0}});
        
        // Direction vectors: Right, Left, Down, Up
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!minHeap.empty()) {
            pip curr = minHeap.top();
            minHeap.pop();

            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if (visited[x][y]) 
                continue;

            // If we reach the bottom-right corner, return the cost
            if (x == m - 1 && y == n - 1) 
                return cost;

            visited[x][y] = true;

            // Explore all four directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (isValid(newX, newY, m, n) && !visited[newX][newY]) {
                    int newCost = cost;
                    // Add cost if moving in a different direction
                    newCost += (i + 1) == grid[x][y] ? 0 : 1;
                    minHeap.push({newCost, {newX, newY}});
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    cout << "Output (grid1): " << sol.minCost(grid1) << endl;

    // Test Case 2
    vector<vector<int>> grid2 = {{1,1,3},{3,2,2},{1,1,4}};
    cout << "Output (grid2): " << sol.minCost(grid2) << endl;

    // Test Case 3
    vector<vector<int>> grid3 = {{1,2},{4,3}};
    cout << "Output (grid3): " << sol.minCost(grid3) << endl;

    return 0;
}

