#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    int findMinSwaps(vector<int>& values) {
        int min_swaps = 0;
        map<int, int> sorted_map;
        int n = values.size();
        for (int j = 0; j < n; ++j)
            sorted_map[values[j]] = j;
        sort(values.begin(), values.end());
        vector<bool> visited(n, false);
        int iteration = 0;
        for (auto& [val, idx] : sorted_map) {
            if (visited[idx]) {
                iteration++;
                continue;
            }
            visited[idx] = true;
            int len = 1;
            while (idx != iteration) {
                idx = sorted_map[values[idx]];
                visited[idx] = true;
                len++;
            }
            min_swaps += len - 1;
            iteration++;
        }
        return min_swaps;
    }

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int min_swaps = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> values;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                values.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            min_swaps += findMinSwaps(values);
        }
        return min_swaps;
    }
};

// Helper function to create a binary tree from a vector of integers
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Main function to test the solution
int main() {
    Solution solution;

    vector<vector<int>> testCases = {
        {1, 4, 3, 7, 6, 8, 5, -1, -1, -1, -1, 9, -1, 10},
        {1, 3, 2, 7, 6, 5, 4},
        {1, 2, 3, 4, 5, 6}
    };

    vector<int> expected = {3, 3, 0};

    for (int i = 0; i < testCases.size(); ++i) {
        TreeNode* root = buildTree(testCases[i]);
        int result = solution.minimumOperations(root);
        cout << "Test Case " << i + 1 << ": ";
        cout << "Output: " << result << ", Expected: " << expected[i] << endl;
        cout << (result == expected[i] ? "Pass" : "Fail") << endl;
    }

    return 0;
}

