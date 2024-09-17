class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> res;
        map<string, int> hash1;
        map<string, int> hash2;
        string s;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ' ')
            {
                hash1[s] += 1;
                s.clear();
            }
            else
                s += s1[i];

        }
        if (!s.empty())
            hash1[s] += 1;
        s.clear();
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == ' ')
            {
                hash2[s] += 1;
                s.clear();
            }
            else
                s += s2[i];
        }
        if (!s.empty())
            hash2[s] += 1;

        for (auto it1 = hash1.begin(); it1 != hash1.end(); it1++)
        {
            auto f = hash2.find(it1->first);
            // cout << it1->second << "\n";
            if (f == hash2.end())
            {
                if (it1->second == 1)
                    res.push_back(it1->first);
            }
        }
        for (auto it2 = hash2.begin(); it2 != hash2.end(); it2++)
        {
            auto f = hash1.find(it2->first); 
            // cout << it2->second << "\n";

            if (f == hash1.end())
            {
                if (it2->second == 1)
                    res.push_back(it2->first);
            }
        }
        return res;
    }
};