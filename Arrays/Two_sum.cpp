#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int x)
    {
        vector<int> v(2);
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] == x)
                {
                    v[0] = i;
                    v[1] = j;
                    return v; // Return as soon as a valid pair is found
                }
            }
        }
        // If no pair is found, return an empty vector

        return v;
    }
};

int main()
{
    // Input array and target sum
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    // Create an instance of Solution and call the twoSum function
    Solution solution;
    vector<int> result = solution.twoSum(arr, target);

    // Display the result
    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No solution found" << endl;
    }
    return 0;
}