#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find Bob's path from his node to root (0)
    bool findBobPath(vector<vector<int>>& adj, int bob, int parent, vector<int>& curr_path, vector<int>& bob_path) {
        if (bob == 0) {
            bob_path = curr_path;
            return true;
        }
        curr_path.push_back(bob);
        for (int nbr : adj[bob]) {
            if (nbr != parent && findBobPath(adj, nbr, bob, curr_path, bob_path))
                return true;
        }
        curr_path.pop_back();
        return false;
    }

    // Function to find the maximum possible income for Alice
    int findMaxIncomeForAlice(vector<vector<int>>& adj, int alice, int parent, vector<int>& amount) {
        int max_income = INT_MIN;
        for (int nbr : adj[alice]) {
            if (nbr != parent) {
                int income = findMaxIncomeForAlice(adj, nbr, alice, amount);
                max_income = max(max_income, income + amount[alice]);
            }
        }
        return (max_income == INT_MIN) ? amount[alice] : max_income;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);

        // Step 1: Construct adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Find Bob's path from node bob to root (0)
        vector<int> curr_path, bob_path;
        findBobPath(adj, bob, -1, curr_path, bob_path);

        // Step 3: Modify amount for Bob's path
        int size = bob_path.size();
        for (int i = 0; i < size / 2; ++i)
            amount[bob_path[i]] = 0;

        if (size % 2 == 0) 
            amount[bob_path[size / 2]] /= 2;
        else 
            amount[bob_path[size / 2]] = 0;

        // Step 4: Use DFS to find max income for Alice
        return findMaxIncomeForAlice(adj, 0, -1, amount);
    }
};

// **Driver Code**
int main() {
    Solution sol;

    vector<tuple<vector<vector<int>>, int, vector<int>>> testCases = {
        {{{0,1},{1,2},{1,3},{3,4}}, 3, {-2,4,2,-4,6}},   // Example 1
        {{{0,1}}, 1, {-7280,2350}}  // Example 2
    };

    for (auto& test : testCases) {
        int result = sol.mostProfitablePath(get<0>(test), get<1>(test), get<2>(test));
        cout << "Output: " << result << endl;
    }

    return 0;
}

