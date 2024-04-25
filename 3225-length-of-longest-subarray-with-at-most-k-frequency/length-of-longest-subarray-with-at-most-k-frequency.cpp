class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        map<int, int> hash;
        int left = 0;
        int right = 0;
        int ans = 0;

        while (right < nums.size())
        {
            if (hash[nums[right]] < k)
            {
                hash[nums[right]] += 1;
                right++;
            }
            else
            {
                ans = max(ans, right - left);
                hash[nums[left]] -= 1;
                left++;
            }
        }
        while (left < right)
        {
            ans = max(ans, right - left);
            hash[nums[left]] -= 1;
            left++;
        }

        return ans;
    }
};