#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < (n - 1) && nums[i] == nums[i + 1])
                continue;
            else
            {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main()
{
    // Input array with duplicates (sorted as per the problem requirements)
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5};

    Solution solution;

    // Call removeDuplicates function
    int newLength = solution.removeDuplicates(nums);

    // Output the modified array and its new length
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New Length: " << newLength << endl;

    return 0;
}