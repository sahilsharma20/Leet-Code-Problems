#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    unordered_map<int, int> mem; // Memoization map to store already computed results

    // Recursive function to calculate the minimum cost
    int solve(vector<int>& days, vector<int>& costs, int pos) {
        // Base case: if all days are processed, no cost is needed
        if (pos >= days.size()) return 0;

        // If result is already computed for the current position, return it
        if (mem.count(pos)) return mem[pos];

        // Consider three options for buying passes
        // 1-day pass
        int nextPos = pos + 1;
        int oneDayCost = costs[0] + solve(days, costs, nextPos);

        // 7-day pass
        while (nextPos < days.size() && days[nextPos] <= days[pos] + 6) {
            nextPos++;
        }
        int sevenDayCost = costs[1] + solve(days, costs, nextPos);

        // 30-day pass
        nextPos = pos + 1;
        while (nextPos < days.size() && days[nextPos] <= days[pos] + 29) {
            nextPos++;
        }
        int thirtyDayCost = costs[2] + solve(days, costs, nextPos);

        // Store the minimum cost for the current position
        return mem[pos] = min({oneDayCost, sevenDayCost, thirtyDayCost});
    }

public:
    // Function to calculate the minimum cost of tickets
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        mem.clear(); // Clear memoization for new test cases
        return solve(days, costs, 0); // Start solving from the first day
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> days1 = {1, 4, 6, 7, 8, 20};
    vector<int> costs1 = {2, 7, 15};
    cout << "Input: days = [1,4,6,7,8,20], costs = [2,7,15]" << endl;
    cout << "Output: " << solution.mincostTickets(days1, costs1) << endl;

    // Example 2
    vector<int> days2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs2 = {2, 7, 15};
    cout << "Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]" << endl;
    cout << "Output: " << solution.mincostTickets(days2, costs2) << endl;

    return 0;
}

