class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int res = INT_MAX;

        for (int i = 0; i < blocks.size(); i++)
        {
            string s = blocks.substr(i, k);
            if (s.size() == k)
                res = min(res, countwhite(s));
        }
        return res;
    }

    int countwhite(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'W')
                count++;
        }
        return count;
    }
};