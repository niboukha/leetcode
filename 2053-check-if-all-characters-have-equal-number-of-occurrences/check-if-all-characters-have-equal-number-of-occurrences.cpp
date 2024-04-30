class Solution {
public:
    bool areOccurrencesEqual(string s)
    {
        vector<int> hash(26, 0);
        int         val = 0;

        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] += 1;
            val = max(val, hash[s[i] - 'a']);
        }
        for (int i = 0; i < hash.size(); i++)
        {
            if (hash[i] != 0 and val != hash[i])
                return false;
        }
        return true;
    }
};