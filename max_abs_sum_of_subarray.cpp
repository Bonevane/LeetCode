class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int maxSum = nums[0], minSum = nums[0], 
            tempMax = nums[0], tempMin = nums[0];
    
            for (int i = 1; i < nums.size(); i++) {
                tempMax = max(tempMax + nums[i], nums[i]);
                tempMin = min(tempMin + nums[i], nums[i]);
    
                maxSum = max(maxSum, tempMax);
                minSum = min(minSum, tempMin);
            }
    
            return max(abs(maxSum), abs(minSum));
        }
    };