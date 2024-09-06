class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        int left = 1;
        int right = nums.size() - 1;
        int sum = 0;
        int i = 0;
        
        sort(nums.begin(), nums.end());
        while (i <= nums.size() - 2 and left < right)
        {
            sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else
            {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right and nums[right] == nums[right - 1])
                    right--;
                while (left < right and nums[left] == nums[left + 1])
                    left++;
                if (left < right and nums[left] != nums[left + 1] and nums[right] != nums[right - 1])
                {
                    left++;
                    right--;
                }
            }
            if (i < left and left >= right)
            {
                while (i < nums.size() - 2 and nums[i] == nums[i + 1])
                    i++;
                if (nums[i] != nums[i + 1])
                    i++;
                left = i + 1;
                right = nums.size() - 1;
            }
        }
        return res;
    }
};