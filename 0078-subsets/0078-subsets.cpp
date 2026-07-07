class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(int idx, vector<int>& nums) {

        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[idx]);
        solve(idx + 1, nums);

        // Backtrack
        subset.pop_back();

        // Exclude current element
        solve(idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(0, nums);

        return ans;
    }
};