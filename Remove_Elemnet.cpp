#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& arr, int x) {
        int count = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] != x ){
                arr[count] = arr[i];
                count++;
            }            
        }
    return count;
    }
};

int main()
{
    // Input array with duplicates (sorted as per the problem requirements)
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    
    Solution solution;
    
    int newLength = solution.removeElement(arr, 2);
    
    // Output the result
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of unique elements: " << newLength << endl;

    return 0;
}

