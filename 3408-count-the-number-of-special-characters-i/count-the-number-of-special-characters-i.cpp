class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        vector< pair<int, int> > hash(26, std::make_pair(0, 0));
        int                      compt = 0;

        for (int i = 0; i < word.size(); i++)
        {
            if (isupper(word[i]))
                hash[word[i] - 'A'].first += 1;
            else
                hash[word[i] - 'a'].second += 1;
        }
        for (size_t i = 0; i < hash.size(); i++)
        {
            if (hash[i].first >= 1 and hash[i].second >= 1)
                compt++;
        }
        return compt;
    }
};