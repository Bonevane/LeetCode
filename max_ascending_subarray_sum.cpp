class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], tempSum = nums[0], size = nums.size();

        for (int i = 0; i < size - 1; i++) {
            if (nums[i] < nums[i + 1])
                tempSum += nums[i + 1];
            else
                tempSum = nums[i + 1];

            maxSum = max(maxSum, tempSum);
        }

        return maxSum;
    }
};