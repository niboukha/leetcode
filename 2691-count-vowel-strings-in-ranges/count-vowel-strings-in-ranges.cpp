class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        vector<int> res;
        vector<int> pre;

        int count = 0;
        pre.push_back(count);
        for (int i = 0; i < words.size(); i++)
        {
            if(is_vowel(words[i][0]) and is_vowel(words[i][words[i].size() - 1]))
                count++;
            pre.push_back(count);
        }

        for (int i = 0; i < queries.size(); i++)
            res.push_back(pre[queries[i][queries[i].size() - 1] + 1] - pre[queries[i][0]]);

        return res;
    }

    bool is_vowel(char c)
    {
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
            return true;
        return false;
    }
};