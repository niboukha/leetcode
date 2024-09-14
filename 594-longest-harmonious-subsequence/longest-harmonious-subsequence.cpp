class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        map<int , int> hash;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]] += 1;
        
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            auto f = hash.find(it->first + 1);
            if (f != hash.end())
            {
                res = max (res,it->second + f->second);
            }
        }
        return res;
    }
};