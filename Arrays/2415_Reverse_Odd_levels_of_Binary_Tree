#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to reverse the values at odd levels of a binary tree
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> level_nodes;

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                level_nodes.push_back(curr);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (level % 2 == 1) {
                int n = level_nodes.size();
                for (int j = 0; j < n / 2; ++j)
                    swap(level_nodes[j]->val, level_nodes[n - j - 1]->val);
            }

            level++;
        }

        return root;
    }
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Function to print the tree in level-order
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {2, 3, 5, 8, 13, 21, 34},  // Case 1: root = [2,3,5,8,13,21,34]
        {7, 13, 11},              // Case 2: root = [7,13,11]
        {0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2} // Case 3: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
    };

    Solution solution;

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << " Input: ";
        for (int num : testCases[i]) cout << num << " ";
        cout << endl;

        TreeNode* root = buildTree(testCases[i]);
        cout << "Original Tree Level Order: ";
        printLevelOrder(root);

        root = solution.reverseOddLevels(root);

        cout << "Tree After Reversing Odd Levels: ";
        printLevelOrder(root);
        cout << endl;
    }

    return 0;
}

