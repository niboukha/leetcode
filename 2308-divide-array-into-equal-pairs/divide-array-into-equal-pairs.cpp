class Solution {
public:
    bool divideArray(vector<int>& nums)
    {
        map<int, int> hash;
        int cnt = 0;
        for (size_t i = 0; i < nums.size(); i++)
            hash[nums[i]] += 1;
        
        for (map<int, int>::iterator i = hash.begin();
            i != hash.end(); i++)
        {
            if (!(i->second % 2))
                cnt += i->second / 2;
        }
        if (nums.size() / 2 == cnt)
            return true;
        return false;
    }
};