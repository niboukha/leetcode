class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int left = 0;
        int right = left + 1;
        int res = 0;

        while (left < nums.size() and right <= nums.size())
        {
            if (right < nums.size() and nums[left] == nums[right])
            {
                right++;
                continue;
            }
            left++;
            res++;
            if (right < nums.size())
                nums[left] = nums[right];
            right++;
        }

        return res;
    }
};
