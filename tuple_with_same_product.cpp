class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int m = nums.size(), totalNumOfTuples = 0, sameProductCount = 0;

        vector<int> productPairs;

        for (int i = 0; i < m; i++){
            for (int j = i + 1; j < m; j++){
                productPairs.push_back(nums[i] * nums[j]);
            }
        }

        sort(productPairs.begin(), productPairs.end());

        for (int i = 0; i < productPairs.size() - 1; i++){
            if (productPairs[i] == productPairs[i + 1]){
                sameProductCount++;
            }
            else {
                totalNumOfTuples += 8 * ((sameProductCount - 1) * sameProductCount / 2);
                sameProductCount = 1;
            }
        }

        totalNumOfTuples += 8 * ((sameProductCount - 1) * sameProductCount / 2);

        return totalNumOfTuples;
    }
};