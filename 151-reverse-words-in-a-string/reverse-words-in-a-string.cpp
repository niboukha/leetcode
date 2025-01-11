class Solution {
public:
    string reverseWords(string s)
    {
        int i = 0;
        int j = 0;
        int last;
        string ret;

        reverse(s.begin(), s.end());
        s.erase(s.find_last_not_of(' ') + 1);   
        s.erase(0, s.find_first_not_of(' '));
        s.erase(std::unique(std::begin(s), std::end(s), [](unsigned char a, unsigned char b){
        return std::isspace(a) && std::isspace(b);
    }), std::end(s));
        while (i < s.length() and j < s.length())
        {
            if (!isspace(s[j]))
            {
                j++;
                if (j < s.length())
                    continue;
            }

            last = j;
            j--;
            while (i < j)
                swap(s[i++], s[j--]);
            last++;
            i = j = last;
        }
        return s;    
    }
};
