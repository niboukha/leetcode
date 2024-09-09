class Solution {
public:
    int longestPalindrome(string s)
    {
        map<char, int> hash;
       int len = 0;
        int maxodd = 0;

        for (int i = 0; i < s.length(); i++)
        {
            hash[s[i]] += 1;
            if (hash[s[i]] % 2 == 0)
            {
                len += hash[s[i]];
                hash[s[i]] = 0;
            }
            else if (hash[s[i]] % 2 != 0)
                maxodd = 1;
        }
        if (maxodd == 1 and len < s.length())
            len += 1;
        return len;    
    }
};