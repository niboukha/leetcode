class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        std::map<std::string, int> hash;
        std::string res;
        int len = 0;
        std::string s;

        for (int i = 0; i < paragraph.size(); i++)
        {
            if ((paragraph[i] != ' ' and paragraph[i] != '!' and
                paragraph[i] != '?' and paragraph[i] != '\'' and
                paragraph[i] != ',' and paragraph[i] != ';' and paragraph[i] != '.'))
            {
                s += tolower(paragraph[i]);
            }
            else if (!s.empty())
            {
                auto it = find(banned.begin(), banned.end(), s);
                if (it == banned.end())
                {
                    hash[s] += 1;
                    if (len <= hash[s])
                    {
                        res = s;
                        len = max(len, hash[s]);
                    }
                }
                s.clear();
            }
            if(!s.empty() and i == paragraph.size() - 1)
            {
                 auto it = find(banned.begin(), banned.end(), s);
                if (it == banned.end())
                {
                    hash[s] += 1;
                    if (len <= hash[s])
                    {
                        res = s;
                        len = max(len, hash[s]);
                    }
                }
                s.clear();
            }
        }
        return res;
    }
};