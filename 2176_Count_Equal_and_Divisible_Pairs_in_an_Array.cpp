class Solution {
public:
    static int countPairs(const vector<int>& a, int k) {
        const int n = a.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            const int ai = a[i];
            for (int j = i + 1; j < n; ++j) {
                if (ai == a[j] && (i * j) % k == 0)
                    ++count;
            }
        }
        return count;
    }
};
