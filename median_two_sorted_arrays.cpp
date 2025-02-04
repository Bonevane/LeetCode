class Solution {
public:
    int a = 0, b = 0;

    int findNextSmallest(vector<int>& nums1, vector<int>& nums2){
        if (a < nums1.size() && b < nums2.size())
            return nums1[a] < nums2[b] ? nums1[a++] : nums2[b++];
        else if (a < nums1.size())
            return nums1[a++];
        else if (b < nums2.size())
            return nums2[b++];
        return 0;
    }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), temp;

        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; i++){
                temp = findNextSmallest(nums1, nums2);
            }
            return (double)(findNextSmallest(nums1, nums2) 
                    + findNextSmallest(nums1, nums2)) / 2;
        }
        else {
            for (int i = 0; i < (m + n) / 2; i++){
                temp = findNextSmallest(nums1, nums2);
            }
            return findNextSmallest(nums1, nums2);
        }

        return 0;
    }
};