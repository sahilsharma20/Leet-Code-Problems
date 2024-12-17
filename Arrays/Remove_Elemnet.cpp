#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &arr, int x)
    {
        int count = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != x)
            {
                arr[count] = arr[i];
                count++;
            }
        }
        return count;
    }
};

int main()
{
    // Input array
    vector<int> arr = {3, 2, 2, 3, 4, 5, 3, 6};
    int x = 3; // Element to remove

    // Create an instance of the Solution class
    Solution solution;

    // Call removeElement method
    int newLength = solution.removeElement(arr, x);

    // Output the result
    cout << "Array after removing " << x << ": ";
    for (int i = 0; i < newLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "New length of the array: " << newLength << endl;

    return 0;
}
