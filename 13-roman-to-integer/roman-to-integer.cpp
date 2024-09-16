class Solution {
public:
    int romanToInt(string s)
    {
        std::map<char, int> hash = {{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};
        
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (i - 1 >= 0 and (s[i] == 'V' or s[i] == 'X') and s[i - 1] == 'I')
            {
                res += hash[s[i]] - 1;
                i--;
            }
            else if (i - 1 >= 0 and (s[i] == 'L' or s[i] == 'C') and s[i - 1] == 'X')
            {
                res += hash[s[i]] - 10;
                i--;
            }
            else if (i - 1 >= 0 and (s[i] == 'M' or s[i] == 'D') and s[i - 1] == 'C')
            {
                res += hash[s[i]] - 100;
                i--;
            }
            else
                res += hash[s[i]];
        }
        return res;
    }
};