class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        set<int> window;
        int l = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (r - l > k)
            {
                window.erase(nums[l]);
                l++;
            }
            auto it = window.find(nums[r]);
            if (it != window.end())
                return true;
            window.insert(nums[r]);
        }
        return false;
    }
};
