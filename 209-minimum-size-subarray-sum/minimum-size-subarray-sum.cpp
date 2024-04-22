class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int len = INT_MAX;

        while (right < nums.size())
        {
            if (sum < target)
            {
                sum += nums[right];
                right++;
            }
            else if (sum >= target)
            {
                len = min(len, right - left);
                sum -= nums[left];
                left++;
            }
        }
        while (left < nums.size())
        {
            if (sum >= target)
            {
                len = min(len, right - left);
                sum -= nums[left];
            }
            left++;
        }
        if (len == INT_MAX)
            len = 0;
        return len;
    }
};
