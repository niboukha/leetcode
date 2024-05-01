class Solution {
public:
    char repeatedCharacter(string s)
    {
        vector<int> hash(26, 0);

        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] += 1;
            if (hash[s[i] - 'a'] == 2)
                return s[i];
        } 
        return s[0];
    }
};