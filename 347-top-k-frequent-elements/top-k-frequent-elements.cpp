class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> hash;
        vector<int> res;
        int m = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] += 1;
            m = max(m, hash[nums[i]]);
        }

        vector<vector<int>> b(m + 1);
        map<int, int>::iterator it = hash.begin();

        for (; it != hash.end(); it++)
            b[it->second].push_back(it->first);
        for (int i = b.size() - 1; i > 0; i--)
        {
            if (res.size() < k)
            {
                for (int j = 0; j < b[i].size(); j++)
                  res.push_back(b[i][j]);
            }
        }

        return res;
    }
};