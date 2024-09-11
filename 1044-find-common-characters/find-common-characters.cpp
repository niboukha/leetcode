class Solution {
public:
    vector<string> commonChars(vector<string>& words)
    {
        map<string, vector<int>> hash;
        vector<string> res;

        for (int i = 0; i < words.size(); i++)
        {
            hash[words[i]] = std::vector<int>(26, 0);
            for (int j = 0; j < words[i].size(); j++)
            {
                hash[words[i]][words[i][j] - 'a'] += 1;
            }
        }

        int a = 0;
        int exit = 0;
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
                    cout << "hna ----> ";
                }
                else
                {
                    exit = 0;
                    break;
                }
                cout << it->first << "-" << it->second[i] << "-" << a;
                cout << "\t";
            }
            cout << exit << " " << string(1, i + 'a') << "\n";
            if (exit != 0)
            {
            //     int k = exit / words.size();
                while (m > 0)
                {
                    res.push_back(string(1, i + 'a'));
                    m--;
                }
            }
            // else if (exit >= words.size())
            //         res.push_back(string(1, i + 'a'));
            exit = 0;
            // m = INT_MAX;
            cout << "\n";
        }

        return res;
    }
};