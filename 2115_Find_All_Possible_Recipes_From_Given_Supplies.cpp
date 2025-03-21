#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        
        // Initialize indegree and graph
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
        }
        
        queue<string> q;
        vector<string> result;
        
        // Push initial supplies into queue
        for (const string& item : supplies) {
            q.push(item);
        }
        
        // Process the queue
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            
            // If current is a recipe, add to result
            if (indegree.find(current) != indegree.end()) {
                result.push_back(current);
            }
            
            // Reduce indegree of dependent recipes
            for (const string& next : graph[current]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
    vector<string> supplies = {"yeast", "flour", "meat"};
    
    vector<string> result = sol.findAllRecipes(recipes, ingredients, supplies);
    
    for (const string& recipe : result) {
        cout << recipe << " ";
    }
    cout << endl;
    return 0;
}
