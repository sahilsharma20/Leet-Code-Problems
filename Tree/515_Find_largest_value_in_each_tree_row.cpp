#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val; // Value of the node
    TreeNode *left; // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value initialization
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children initialization
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> result; // Stores the largest values at each depth

    // Depth First Search helper function
    void DFS(TreeNode* root, int depth) {
        if (!root) return;

        // If it's a new depth, add the current node's value
        if (depth == result.size()) {
            result.push_back(root->val);
        } else {
            // Update the largest value for the current depth
            result[depth] = max(result[depth], root->val);
        }

        // Recur for left and right children
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }

    // Main function to find the largest values in each row
    vector<int> largestValues(TreeNode* root) {
        result.clear(); // Clear result for each call
        DFS(root, 0);   // Start DFS from root at depth 0
        return result;
    }
};

// Function to build a tree for the first input example
TreeNode* buildTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

// Function to build a tree for the second input example
TreeNode* buildTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;

    // Test case 1
    TreeNode* root1 = buildTree1();
    vector<int> result1 = sol.largestValues(root1);
    cout << "Largest values for tree 1: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    // Test case 2
    TreeNode* root2 = buildTree2();
    vector<int> result2 = sol.largestValues(root2);
    cout << "Largest values for tree 2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup dynamically allocated memory for tree 1
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right->right;
    delete root1->right;
    delete root1;

    // Cleanup dynamically allocated memory for tree 2
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}

