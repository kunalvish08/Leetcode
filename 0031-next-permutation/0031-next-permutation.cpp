class Solution {
public:
    void nextPermutation(vector<int> &nums)
{

    int bp = -1;
    // finding the break point
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            bp = i;
            break;
        }
    }
    // first greater element from back
    if (bp != -1)
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[bp])
            {
                swap(nums[i], nums[bp]);
                break;
            }
        }
    }
    // reverse the array from bp+1 to end
    reverse(nums.begin() + bp + 1, nums.end());
}
};