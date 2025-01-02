class Solution {
public:
    int minDeletions(string s)
    {
        int res = 0;

        map<char, int> freqMap;
        set<int> freqSet;

        for (int i = 0; i < s.size(); i++)
            freqMap[s[i]] += 1;
        
        for (auto& pair : freqMap)
        {
            // std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            while (freqSet.find(pair.second) != freqSet.end())
            {
                // cout << pair.second << "\n";
                pair.second--;
                res++;
            }
            // cout << pair.second<<"---\n";
            if (pair.second != 0)
                freqSet.insert(pair.second);
        }

        return res;
    }
};