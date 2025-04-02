class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            if (n < 3) return 0;
            long long res = 0, imax = 0, dmax = 0;
            // First update the final result, then update nums[i] - nums[j]
            // then update nums[i]
            // Think of it as a delay of 1 iteration for both dmax and imax
            for (int k = 0; k < n; k++) {
                res = max(res, dmax * nums[k]);
                dmax = max(dmax, imax - nums[k]);
                imax = max(imax, (long long)(nums[k]));
            }
            return res;
        }
    };