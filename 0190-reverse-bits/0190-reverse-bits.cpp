class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {  // Iterate for all 32 bits
            res = (n & 1) + (res << 1);
            n >>= 1;
        }
        return res;
    }
};
