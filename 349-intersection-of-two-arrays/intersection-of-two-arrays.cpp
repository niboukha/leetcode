class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        map<int, int> hash1;    
        map<int, int> hash2;
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++)
            hash1[nums1[i]] = 1;
        for(int i = 0; i < nums2.size(); i++)
        {
            if (hash1[nums2[i]] == 1)
                hash2[nums2[i]] = 1;
        }
        for(map<int, int>::iterator i = hash2.begin(); i != hash2.end(); i++)
        {
            if (i->second == 1)
                ans.push_back(i->first);
        }      
        return ans;
    }
};