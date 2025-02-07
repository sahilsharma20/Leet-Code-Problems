#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> color_freq; // Stores frequency of each color
        unordered_map<int, int> ball_color; // Stores current color of each ball
        vector<int> res;

        for (auto& q : queries) {
            int ball = q[0], color = q[1];

            // If ball was previously painted, reduce old color frequency
            if (ball_color.count(ball)) {
                int old_color = ball_color[ball];
                if (--color_freq[old_color] == 0) {
                    color_freq.erase(old_color);
                }
            }

            // Paint the ball with the new color
            ball_color[ball] = color;
            color_freq[color]++;

            // Store the number of distinct colors in res
            res.push_back(color_freq.size());
        }

        return res;
    }
};

// Driver function
int main() {
    Solution sol;

    vector<pair<int, vector<vector<int>>>> test_cases = {
        {4, {{1,4}, {2,5}, {1,3}, {3,4}}},  // Expected output: [1,2,2,3]
        {4, {{0,1}, {1,2}, {2,2}, {3,4}, {4,5}}} // Expected output: [1,2,2,3,4]
    };

    for (auto& [limit, queries] : test_cases) {
        cout << "Input: limit = " << limit << ", queries = { ";
        for (auto& q : queries) cout << "[" << q[0] << "," << q[1] << "] ";
        cout << "}\n";

        vector<int> result = sol.queryResults(limit, queries);
        cout << "Output: { ";
        for (int r : result) cout << r << " ";
        cout << "}\n\n";
    }

    return 0;
}

