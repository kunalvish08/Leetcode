
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<long long> diff(n);

        long long sum = 0;
        long long mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (sum <= k)
            return 0;

        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long need = 0;

            for (int i = 0; i < n; i++) {
                if (diff[i] > mid)
                    need += diff[i] - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long level = low;
        long long used = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > level) {
                used += diff[i] - level;
                diff[i] = level;
            }
            ans += diff[i] * diff[i];
        }

        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == level && level > 0) {
                ans -= level * level;
                ans += (level - 1) * (level - 1);
                remaining--;
            }
        }

        return ans;
    }
};
