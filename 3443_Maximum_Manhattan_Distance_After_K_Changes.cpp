class Solution {
public:
    int maxDistance(string s, int k) {
        int length = s.length();
        int up = 0, down = 0, right = 0, left = 0;
        int max_distance = 0;

        for (int index = 0; index < length; ++index) {
            if (s[index] == 'N') {
                up++;
            } else if (s[index] == 'S') {
                down++;
            } else if (s[index] == 'E') {
                right++;
            } else if (s[index] == 'W') {
                left++;
            }

            int vertical_shift = abs(up - down);
            int horizontal_shift = abs(right - left);
            int base_distance = vertical_shift + horizontal_shift;

            int interfering_moves = min(up, down) + min(right, left);
            int max_possible_distance = base_distance + min(k, interfering_moves) * 2;

            max_distance = max(max_distance, min(index + 1, max_possible_distance));
        }
              return max_distance;

    }
};
