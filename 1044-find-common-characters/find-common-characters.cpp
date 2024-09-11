class Solution {
public:
    vector<string> commonChars(vector<string>& words)
    {
        map<string, vector<int>> hash;
        vector<string> res;
        int a = 0;
        int exit = 0;

        for (int i = 0; i < words.size(); i++)
        {
            hash[words[i]] = std::vector<int>(26, 0);
            for (int j = 0; j < words[i].size(); j++)
            {
                hash[words[i]][words[i][j] - 'a'] += 1;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            int m = INT_MAX;
            map<string, vector<int>>::iterator it = hash.begin();

            a = it->second[i];
            for (; it != hash.end(); it++)
            {
                if (it->second[i] >= 1 and a != 0)
                {
                    m = min(m, it->second[i]);
                    exit += it->second[i];
                }
                else
                {
                    exit = 0;
                    break;
                }
            }
            if (exit != 0)
            {
                while (m > 0)
                {
                    res.push_back(string(1, i + 'a'));
                    m--;
                }
            }
            exit = 0;
        }

        return res;
    }
};