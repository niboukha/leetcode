class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
        vector<int> hash(101, 0);
        int ans = 0;

        for(int i = 0; i < nums.size(); i++)
            hash[nums[i]] += 1;
        for(int i = 0; i < hash.size(); i++)
        {
            if (hash[i] == 1)
                ans += i;
        }
        return ans;
    }
};