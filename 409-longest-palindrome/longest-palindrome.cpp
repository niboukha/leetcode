class Solution {
public:
    int longestPalindrome(string s)
    {
        vector<int> hash(128, 0);
        int len = 0;
        int maxodd = 0;

        for (int i = 0; i < s.length(); i++)
        {
            hash[s[i]] += 1;
            if (hash[s[i]] % 2 == 0)
            {
                len += hash[s[i]];
                hash[s[i]] = 0;
                cout << s[i] << " " << len << "\n";
            }
            else if (hash[s[i]] % 2 != 0)
            {
                maxodd = 1;
                cout << "-> " << s[i] << " " << len << " " << maxodd << "\n";
            }
        }
        if (maxodd == 1 and len < s.length())
        {
            len += 1;
            cout << len << " " << "dkhgel \n";
        }
        
        return len;    
    }
};