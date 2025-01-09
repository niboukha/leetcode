class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int res = 0;
        map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] += 1;
            res = max(res, hash[nums[i]]);
        }

        map<int, int>::iterator it = hash.begin();

        while (it != hash.end()) {
            if (it->second == res)
                return it->first;
            ++it;
        }

        return res;
    }
};