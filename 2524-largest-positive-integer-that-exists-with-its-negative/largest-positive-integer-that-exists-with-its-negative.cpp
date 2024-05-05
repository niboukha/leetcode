class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        map<int, pair<int, int>> hash;
        int ans = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0 and hash[nums[i]].second == 1)
                ans = max(ans, nums[i]);
            else if (nums[i] <= 0 and hash[nums[i] * -1].first == 1)
                ans = max(ans, -1 * nums[i]);
            else
            {
                if (nums[i] > 0)
                    hash[nums[i]].first = 1;
                else
                    hash[nums[i] * -1].second = 1;
            }
        }
        return ans;
    }
};