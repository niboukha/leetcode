class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        vector<pair<int, int> > hash(26, std::make_pair(0, 0));
        int                     ans = 0;

        for (size_t i = 0; i < word.length(); i++)
        {
            if (isupper(word[i]) and hash[word[i] - 'A'].second >= 0)
                hash[word[i] - 'A'].first += 1;
            else if (isupper(word[i]) and hash[word[i] - 'A'].second == 0)
                hash[word[i] - 'A'].second = -1;
            else if (islower(word[i]) and hash[word[i] - 'a'].first == 0)
                hash[word[i] - 'a'].second += 1;
            else if (islower(word[i]) and hash[word[i] - 'a'].first >= 0)
                hash[word[i] - 'a'].second = -1;
        }

        for (size_t i = 0; i < hash.size(); i++)
        {
            if (hash[i].first > 0 and hash[i].second > 0)
                ans++;
        }
        return ans;
    }
};