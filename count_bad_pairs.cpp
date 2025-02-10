class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int m = nums.size();
            unordered_map<int, int> map;
            long long int result = 0;
    
            for (int i = 0; i < m; i++){
                result += i - map[i - nums[i]];
    
                map[i - nums[i]] = map[i - nums[i]] + 1;
            }
    
            return result;
        }
    };