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
            if (paragraph[i] != ' ' and paragraph[i] != '!' and
                paragraph[i] != '?' and paragraph[i] != '\'' and
                paragraph[i] != ',' and paragraph[i] != ';' and paragraph[i] != '.')
                {
                    s += tolower(paragraph[i]);
                    cout << s << " " << i << "\n";
                }
            else if (!s.empty())
            {
                cout << "---> " << s << " |" << paragraph[i] << "|\n";
                auto it = find(banned.begin(), banned.end(), s);
                if (it == banned.end())
                {
                    cout << "-----> " << s << "\n";
                    hash[s] += 1;
                    if (len <= hash[s])
                    {
                        res = s;
                        len = max(len, hash[s]);
                        cout << "====> " << res << " " << hash[s] << " " << len << "\n";
                    }
                }
                s.clear();
            }
        }
        if (!s.empty())
        {
            auto it = find(banned.begin(), banned.end(), s);
            if ( it == banned.end())
            {
                cout << "-----> t7t " << s << " " << len << "\n";
                hash[s] += 1;
                if (len <= hash[s])
                {
                    res = s;
                    len = max(len, hash[s]);
                    cout << "====> " << res << " " << hash[s] << " " << len << "\n";
                }
            }
        }
        return res;
    }
};