#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int getVal(string& traversal, int& pos) {
        int val = 0;
        while (pos < traversal.size() && isdigit(traversal[pos])) {
            val = val * 10 + (traversal[pos] - '0');
            pos++;
        }
        return val;
    }

    int getDashLen(string& traversal, int& pos) {
        int dash_len = 0;
        while (pos < traversal.size() && traversal[pos] == '-') {
            dash_len++;
            pos++;
        }
        return dash_len;
    }

    void buildTree(TreeNode* curr, int expectedDepth, string& traversal, int& pos) {
        if (pos >= traversal.size()) return;

        int prevPos = pos;
        int dashLen = getDashLen(traversal, pos);

        // If new node's depth is less than expected, rollback and return
        if (dashLen < expectedDepth) {
            pos = prevPos;
            return;
        }

        // Get node value and create new node
        int nodeVal = getVal(traversal, pos);
        TreeNode* newNode = new TreeNode(nodeVal);

        // Attach to left or right
        if (!curr->left) curr->left = newNode;
        else curr->right = newNode;

        // Recursive calls for children
        buildTree(newNode, expectedDepth + 1, traversal, pos);
        buildTree(newNode, expectedDepth + 1, traversal, pos);
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        int pos = 0;
        TreeNode* root = new TreeNode(getVal(traversal, pos)); // Root node
        buildTree(root, 1, traversal, pos);  // Build left subtree
        buildTree(root, 1, traversal, pos);  // Build right subtree
        return root;
    }
};

// **Helper function to print the tree in expected format**
string serializeTree(TreeNode* root) {
    if (!root) return "null";
    return "[" + to_string(root->val) + "," + serializeTree(root->left) + "," + serializeTree(root->right) + "]";
}

// **Driver Code**
int main() {
    Solution sol;
    
    vector<string> testCases = {
        "1-2--3--4-5--6--7",
        "1-2--3---4-5--6---7",
        "1-401--349---90--88"
    };

    for (auto& traversal : testCases) {
        TreeNode* root = sol.recoverFromPreorder(traversal);
        cout << serializeTree(root) << endl;
    }

    return 0;
}

