class Solution {
public:
   int subarraySum(vector<int> &nums, int k)
{
    int pref_sum = 0;
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        pref_sum += nums[i];

        if (pref_sum == k)
            ans++;

        if (mp.find(pref_sum - k) != mp.end())
        {
            ans += mp[pref_sum - k];
        }

        mp[pref_sum]++;
    }

    return ans;
}
};