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
public:
    unordered_map<int, int> x2post;  // Maps node values to postorder indices

    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int preS, int postS, int postE) {
        if (postS > postE) return nullptr;  // Base case
        TreeNode* root = new TreeNode(preorder[preS]);
        if (postS == postE) return root;  // Only one node, return as leaf
        
        // Identify left child and find its index in postorder
        int leftRoot = preorder[preS + 1];  
        int leftRootPostIdx = x2post[leftRoot];  

        // Recursively build left and right subtrees
        root->left = buildTree(preorder, postorder, preS + 1, postS, leftRootPostIdx);
        root->right = buildTree(preorder, postorder, preS + (leftRootPostIdx - postS + 2), leftRootPostIdx + 1, postE - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        
        // Map postorder values to their indices
        for (int i = 0; i < n; i++) {
            x2post[postorder[i]] = i;
        }

        return buildTree(preorder, postorder, 0, 0, n - 1);
    }
};

// **Helper function to print tree in required format (without null)**
string serializeTree(TreeNode* root) {
    if (!root) return "";
    
    string res = to_string(root->val);
    
    string left = serializeTree(root->left);
    string right = serializeTree(root->right);
    
    if (!left.empty() || !right.empty()) {  // Only include brackets if there's a child
        res += "[" + left;
        if (!right.empty()) res += "," + right;
        res += "]";
    }

    return res;
}

// **Driver Code**
int main() {
    Solution sol;

    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1,2,4,5,3,6,7}, {4,5,2,6,7,3,1}},  // Example 1
        {{1}, {1}}  // Example 2 (Single node)
    };

    for (auto& test : testCases) {
        TreeNode* root = sol.constructFromPrePost(test.first, test.second);
        cout << serializeTree(root) << endl;
    }

    return 0;
}

