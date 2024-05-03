class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2)
    {
        map<string, int> hash1;    
        map<string, int> hash2;
        int ans = 0;
        for (int i = 0; i < words1.size(); i++)
            hash1[words1[i]] += 1;
        for (int i = 0; i < words2.size(); i++)
        {
            if (hash1[words2[i]] == 1)
                hash2[words2[i]] += 1;
        }
        for (map<string, int>::iterator i = hash2.begin(); i != hash2.end(); i++)
        {
            if (i->second == 1)
                ans++;
        }
        return ans;
    }
};