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
            if (hash1[nums2[i]] == 1 and hash2[nums2[i]] == 0)
            {
                hash2[nums2[i]] = 1;
                ans.push_back(nums2[i]);
            }
        }  
        return ans;
    }
};