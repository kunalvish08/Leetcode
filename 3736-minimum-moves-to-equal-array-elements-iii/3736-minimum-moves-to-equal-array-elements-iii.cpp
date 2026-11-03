
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }

        return maxVal * n - sum;
    }
};