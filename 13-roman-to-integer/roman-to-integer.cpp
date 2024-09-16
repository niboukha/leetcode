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
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] < hash[s[i + 1]])
                res -= hash[s[i]];
            else
                res += hash[s[i]];
        }
        return res;
    }
};