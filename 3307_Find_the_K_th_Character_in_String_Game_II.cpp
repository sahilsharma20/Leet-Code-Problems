class Solution {
public:
    [[nodiscard]] static constexpr char kthCharacter(uint64_t k, const vector<int>& o) noexcept {
        uint8_t r{};
        while (k != 1) {
            r += o[63 - std::countl_zero(k-1)];
            k -= std::bit_ceil(k)/2;
        }
        return 'a' + r % 26;
    }
};
