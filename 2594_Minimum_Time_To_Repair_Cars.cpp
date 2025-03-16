#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long) *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canRepair(ranks, cars, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool canRepair(vector<int>& ranks, int cars, long long time) {
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += (long long) sqrt(time / rank);
            if (totalCars >= cars) return true;
        }
        return false;
    }
};
