class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> hash;
        vector<int> res;
        int m = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // if (nums[i] <= k)
            // {
                hash[nums[i]] += 1;
                m = max(m, hash[nums[i]]);
                cout << "-----> " << nums[i] << "\n";
            // }
        }
        // m = hash.size() + 1;
        vector<vector<int>> b(m + 1);
        map<int, int>::iterator it = hash.begin();

        for (; it != hash.end(); it++)
        {
            b[it->second].push_back(it->first);
            
            cout << b[it->second][0] << " " << it->second << " " << it->first << "\n";
            // cout << "----> " << b[it->second] << "\n";
        }
        for (int i = b.size() - 1; i > 0; i--)
        {
            // cout << b[1][0] << " " << i << "\n";
            if (res.size() < k)
            {
                cout << res.size() << "\n";
                for (int j = 0; j < b[i].size(); j++)
                  res.push_back(b[i][j]);
            }
        }

        return res;
    }
};

            // if (nums[i] <= k and l > 0 and hash[nums[i]] == 1)
            // {
            //     res.push_back(nums[i]);
            //     l--;
            // }
