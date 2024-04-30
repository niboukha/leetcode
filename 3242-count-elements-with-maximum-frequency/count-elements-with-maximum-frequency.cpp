class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        vector<int> hash(101, 0);
        int         ans = 0;
        int         val = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] += 1;
            val = max(val, hash[nums[i]]);
        }
        for(int i = 0; i < hash.size(); i++)
        {
            if (hash[i] == val)
                ans += hash[i];
        }
        return ans;
    }
};