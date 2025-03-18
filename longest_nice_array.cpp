class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int usedBits = 0;     // Tracks bits used in current window
            int windowStart = 0;  // Start position of current window
            int maxLength = 0;    // Length of longest nice subarray found
    
            for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
                while ((usedBits & nums[windowEnd]) != 0) {
                    usedBits ^= nums[windowStart]; 
                    windowStart++;
                }
    
                usedBits |= nums[windowEnd];
                maxLength = max(maxLength, windowEnd - windowStart + 1);
            }
    
            return maxLength;
        }
    };