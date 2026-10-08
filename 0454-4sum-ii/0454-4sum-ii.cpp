 class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> mp;
        int n = nums1.size();

        // nums1 + nums2 ke sums store karo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[nums1[i] + nums2[j]]++;
            }
        }

        int ans = 0;

        // nums3 + nums4 ka opposite sum dhundo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums3[i] + nums4[j];

                if (mp.find(-sum) != mp.end()) {
                    ans += mp[-sum];
                }
            }
        }

        return ans;
    }
};