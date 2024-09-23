class Solution {
public:
    int maximumLengthSubstring(string s)
    {
        vector<int> hash(26, 0);
        int res = 1;
        int k = 0;
        int i = 0;

        while (i < s.size() and k < s.size())
        {
            hash[s[k] - 97] += 1;
            if (hash[s[k] - 97] > 2)
            {
                while ( i < s.size() and hash[s[k] - 97] > 2 )
                {
                    hash[s[i] - 97] -= 1;
                    i++;
                }
            }
            res = max(res, k - i + 1);
            k++;
        }
        return res;

    }
};