#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    #define pii pair<int, int>
    
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pii> q;

        // Step 1: Initialize BFS with all water cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Step 2: BFS to calculate heights
        vector<int> dir = {-1, 0, 1, 0, -1}; // 4-directional movement
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pii curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;

                for (int d = 0; d < 4; ++d) {
                    int newX = x + dir[d];
                    int newY = y + dir[d + 1];

                    if (isValid(newX, newY, m, n) && !visited[newX][newY]) {
                        q.push({newX, newY});
                        height[newX][newY] = level + 1;
                        visited[newX][newY] = true;
                    }
                }
            }
            ++level;
        }

        return height;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> isWater1 = {{0, 1}, {0, 0}};
    vector<vector<int>> result1 = sol.highestPeak(isWater1);
    cout << "Output for Test Case 1:" << endl;
    for (auto row : result1) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    // Test Case 2
    vector<vector<int>> isWater2 = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    vector<vector<int>> result2 = sol.highestPeak(isWater2);
    cout << "Output for Test Case 2:" << endl;
    for (auto row : result2) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}

