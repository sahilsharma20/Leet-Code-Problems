#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    vector<int> segTree; // Segment Tree for Range Maximum Query (RMQ)

    void buildSegmentTree(vector<int>& heights, int start, int end, int st_idx) {
        if (start == end) {
            segTree[st_idx] = start;
            return;
        }

        int mid = start + (end - start) / 2;
        buildSegmentTree(heights, start, mid, 2 * st_idx);
        buildSegmentTree(heights, mid + 1, end, 2 * st_idx + 1);

        segTree[st_idx] = heights[segTree[2 * st_idx]] >= heights[segTree[2 * st_idx + 1]]
                              ? segTree[2 * st_idx]
                              : segTree[2 * st_idx + 1];
    }

    int rangeMaxQuery(vector<int>& heights, int qs, int qe, int start, int end, int st_idx = 1) {
        if (start >= qs && end <= qe) // Total Overlap
            return segTree[st_idx];
        if (start > qe || end < qs) // No Overlap
            return INT_MIN;

        // Partial Overlap
        int mid = start + (end - start) / 2;
        int left_max = rangeMaxQuery(heights, qs, qe, start, mid, 2 * st_idx);
        int right_max = rangeMaxQuery(heights, qs, qe, mid + 1, end, 2 * st_idx + 1);

        if (left_max == INT_MIN) return right_max;
        if (right_max == INT_MIN) return left_max;
        return heights[left_max] >= heights[right_max] ? left_max : right_max;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree = vector<int>(4 * n + 1);
        int st_idx = 1; // Segment Tree Index: Root at index-1

        buildSegmentTree(heights, 0, n - 1, st_idx);

        vector<int> res;
        for (auto query : queries) {
            int alice = min(query[0], query[1]);
            int bob = max(query[0], query[1]);

            if (alice == bob || heights[bob] > heights[alice]) {
                res.push_back(bob);
                continue;
            }

            // Binary Search + RMQ (Range Max Query)
            int low = bob;
            int high = n - 1;
            int ans = INT_MAX;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int rmq = rangeMaxQuery(heights, low, mid, 0, n - 1, st_idx);

                if (heights[rmq] > heights[alice]) {
                    high = mid - 1;
                    ans = min(ans, rmq);
                } else {
                    low = mid + 1;
                }
            }
            if (ans == INT_MAX)
                res.push_back(-1);
            else
                res.push_back(ans);
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> heights1 = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries1 = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    vector<int> result1 = sol.leftmostBuildingQueries(heights1, queries1);
    cout << "Example 1 Results: ";
    for (int r : result1) cout << r << " ";
    cout << endl;

    // Example 2
    vector<int> heights2 = {5, 3, 8, 2, 6, 1, 4, 6};
    vector<vector<int>> queries2 = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
    vector<int> result2 = sol.leftmostBuildingQueries(heights2, queries2);
    cout << "Example 2 Results: ";
    for (int r : result2) cout << r << " ";
    cout << endl;

    return 0;
}

