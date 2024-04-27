class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        map<int, pair<int,int>> hash;
        vector<vector<int> > ans(2);

        for(int i = 0; i < nums1.size(); i++)
        {
            hash[nums1[i]].first += 1;
            hash[nums1[i]].second += 0;
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            hash[nums2[i]].first += 0;
            hash[nums2[i]].second += 1; 
        }
        for(map<int, pair<int,int> >::iterator it = hash.begin(); it != hash.end(); it++)
        {
            if (it->second.first != 0 and it->second.second == 0)
                ans[0].push_back(it->first);
            if (it->second.second != 0 and it->second.first == 0)
                ans[1].push_back(it->first);
        }
        return ans;
    }
};