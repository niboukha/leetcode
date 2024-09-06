class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<string, char>    hash;
        vector<string>      words;
        
        string w;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                w += s[i];
            else
            {
                words.push_back(w);
                w = "";
            }
        }
        if (!w.empty())
            words.push_back(w);
        if (words.size() != pattern.size())
            return false;
        for (size_t i = 0, j = 0; i < words.size(), j < pattern.size(); i++, j++)
        {
            auto it = hash.find(words[i]);

            if (it == hash.end() and searchaboutvalue(hash, pattern[j]) == false)
                hash[words[i]] = pattern[j];
            else if ((it != hash.end() and it->second != pattern[j]) or (it == hash.end() and searchaboutvalue(hash, pattern[j]) == true))
                return false;
        }
        return (true);
    }

   bool   searchaboutvalue(unordered_map<string, char> hash, char c)
    {
        auto it = hash.begin();

        for (; it != hash.end(); it++)
            if (it->second == c)
                return true;
        return false;;

    }
};

