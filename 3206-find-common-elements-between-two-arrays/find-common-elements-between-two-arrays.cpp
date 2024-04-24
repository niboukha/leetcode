class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> hash1(101, 0);
        vector<int> hash2(101, 0);
        vector<int> ans(2, 0);

        for (size_t i = 0; i < nums1.size(); i++)
            hash1[nums1[i]] += 1;
        for (size_t i = 0; i < nums2.size(); i++)
            hash2[nums2[i]] += 1;
        for (size_t i = 0; i< hash1.size(); i++)
        {
            if (hash1[i] >= 1 and hash2[i] >= 1)
            {
                ans[0] += hash1[i];
                ans[1] += hash2[i];
            }
        }
        return ans;
    }
};