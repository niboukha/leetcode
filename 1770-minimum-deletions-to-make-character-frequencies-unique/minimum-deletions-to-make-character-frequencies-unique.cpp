class Solution {
public:
    int minDeletions(string s)
    {
        int res = 0;

        map<char, int>  freqMap;
        set<int>        freqSet;

        for (int i = 0; i < s.size(); i++)
            freqMap[s[i]] += 1;
        
        for (auto& pair : freqMap)
        {
            while (freqSet.find(pair.second) != freqSet.end())
            {
                pair.second--;
                res++;
            }
            if (pair.second != 0)
                freqSet.insert(pair.second);
        }

        return res;
    }
};