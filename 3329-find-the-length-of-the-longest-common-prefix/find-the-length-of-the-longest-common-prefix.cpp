class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        int res = 0;
        unordered_set<int> hashSet;

        for (int i = 0; i < arr1.size(); i++)
        {
            for (int divisor = arr1[i]; divisor >= 1; divisor /= 10)
                hashSet.insert(divisor);
        }
        
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int divisor = arr2[i]; divisor >= 1; divisor /= 10)
            {
                int result = arr2[i] / divisor;
                if (hashSet.find(divisor) != hashSet.end())
                    res = max(res, (int)to_string(divisor).size());
            }
        }
        return res;
    }
};