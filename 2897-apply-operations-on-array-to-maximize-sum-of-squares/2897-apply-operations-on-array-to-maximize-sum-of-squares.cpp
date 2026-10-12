class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(30, 0);

        for (int num : nums) {
            for (int i = 0; i < 30; i++) {
                if (num & (1 << i)) {
                    bits[i]++;
                }
            }
        }

        long long ans = 0;
        const int MOD = 1e9 + 7;

        while (k--) {
            int num = 0;

            for (int i = 0; i < 30; i++) {
                if (bits[i] > 0) {
                    num |= (1 << i);
                    bits[i]--;
                }
            }

            ans = (ans + 1LL * num * num) % MOD;
        }

        return ans;
    }
};