class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        vector<int> odd_frequencies, even_frequencies;

        // Separate odd and even frequencies
        for (const auto &pair : freq) {
            if (pair.second % 2 == 0) {
                even_frequencies.push_back(pair.second);
            } else {
                odd_frequencies.push_back(pair.second);
            }
        }

        // If we don't have both odd and even frequencies, return 0
        if (odd_frequencies.empty() || even_frequencies.empty()) {
            return 0;
        }

        // Calculate the maximum difference
        int max_diff = *max_element(odd_frequencies.begin(), odd_frequencies.end()) -
                       *min_element(even_frequencies.begin(), even_frequencies.end());

        return max_diff;
    }
};
