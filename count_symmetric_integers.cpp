class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; ++num) {
            string str = to_string(num);
            int len = str.length();

            if (len % 2 != 0) continue;

            int half = len / 2;
            int leftSum = 0, rightSum = 0;

            for (int i = 0; i < half; ++i)
                leftSum += str[i] - '0';
            for (int i = half; i < len; ++i)
                rightSum += str[i] - '0';

            if (leftSum == rightSum){
                count++;
                num += 8; // Small optimization since we can expect the next sym num
                          // to appear at minimum 9 nums later
            }
        }

        return count;
    }
};