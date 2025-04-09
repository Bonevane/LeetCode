class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_map<int, int> map;
            for (auto x : nums) {
                if (x < k) 
                    return -1;
                else if (x > k)
                    map[x]++;
            }
            return map.size();
        }
    };