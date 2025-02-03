class Solution {
public:
    bool check(vector<int>& nums) {
        int min = nums[0], pos = 0, len = nums.size();

        for (int i = 1; i < len; i++){
            if (nums[i] <= min && nums[i - 1] != nums[i]){
                min = nums[i];
                pos = i;    
            }
        }

        for (int i = 0; i < len - 1; i++){
            if (nums[(i + pos) % len] > nums[(i + 1 + pos) % len])
                return false;
        }

        return true;
    }
};