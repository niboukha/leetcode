class Solution {
public:
    bool areOccurrencesEqual(string s)
    {
        vector<int> hash(26, 0);
        int         val = 0;

        for(int i = 0; i < s.size(); i++)
            hash[s[i] - 'a'] += 1;
        for (int i = 0; i < hash.size(); i++)
        {
            if (hash[i] != 0 and val == 0)
                val = hash[i];
            if (val != 0 and hash[i] != 0 and val != hash[i])
                return false;
        }
        return true;
    }
};