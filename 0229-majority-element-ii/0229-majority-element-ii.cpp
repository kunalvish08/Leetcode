class Solution {
public:
    vector<int> majorityElement(vector<int> &nums)
{
    int c1 = 0, c2 = 0, vote1 = 0, vote2 = 0;

    // Finding potential candidates
    for (int i = 0; i < nums.size(); i++)
    {
        if (c1 == nums[i])
        {
            vote1++;
        }
        else if (c2 == nums[i])
        {
            vote2++;
        }
        else if (vote1 == 0)
        {
            c1 = nums[i];
            vote1 = 1;
        }
        else if (vote2 == 0)
        {
            c2 = nums[i];
            vote2 = 1;
        }
        else
        {
            vote1--;
            vote2--;
        }
    }

    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;

    // Counting occurrences of potential candidates
    for (auto it : nums)
    {
        if (it == c1)
        {
            cnt1++;
        }
        if (it == c2)
        {
            cnt2++;
        }
    }

    // Checking if candidates appear more than ⌊ n/3 ⌋ times
    if (cnt1 > nums.size() / 3)
    {
        ans.push_back(c1);
    }
    if (cnt2 > nums.size() / 3 && c2 != c1)
    {
        ans.push_back(c2);
    }

    return ans;
}
};