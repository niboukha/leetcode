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
                cout <<"sum-> "<< sum << " " << nums[right] << "\n";
                right++;
            }
            else if (sum >= target)
            {
                len = min(len, right - left);
                sum -= nums[left];
cout << "len -> "<<len<<" "<<nums[left]<<" "<<nums[right]<<" "<<sum<<"\n";
                left++;
            }
        }
cout << "len -> "<<len<<" "<<nums[left]<<" "<<sum<<"\n";
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
