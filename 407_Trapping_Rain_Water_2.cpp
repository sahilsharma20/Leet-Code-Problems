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
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m < 3 || n < 3) // Minimum 3x3 grid required to trap water
            return 0;

        // Step 1: Push all boundary elements as starting points
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Step 2: Apply BFS-like traversal
        int level = 0;
        int trapped_water = 0;
        vector<int> dir = {-1, 0, 1, 0, -1}; // URDL directions

        while (!minHeap.empty()) {
            pip curr = minHeap.top();
            minHeap.pop();

            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level, height);

            // Explore all 4 directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (isValid(newX, newY, m, n) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    minHeap.push({heightMap[newX][newY], {newX, newY}});
                    if (heightMap[newX][newY] < level)
                        trapped_water += level - heightMap[newX][newY];
                }
            }
        }

        return trapped_water;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> heightMap1 = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << "Output (heightMap1): " << sol.trapRainWater(heightMap1) << endl;

    // Test Case 2
    vector<vector<int>> heightMap2 = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    cout << "Output (heightMap2): " << sol.trapRainWater(heightMap2) << endl;

    return 0;
}

