class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res;

        res = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int k = 0;
            if (res.size() > strs[i].size())
                res = res.substr(0, strs[i].size());
            for (int j = 0; j < strs[i].size(); j++)
            {
                if (strs[i][j] != res[k])
                {
                    res = res.substr(0, k);
                    break;
                }
                k++;
            }
        }
        return res;
    }
};