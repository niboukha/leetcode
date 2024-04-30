class Solution {
public:
    int numDifferentIntegers(string word)
    {
        int ans = 0;
        map<string, int> hash;
        for (int i = 0; i < word.size(); i++)
        {
            while (isalpha(word[i]))
                word[i++] = ' ';
        }
        stringstream    ss(word);
        string          s;
        while (ss >> s)
        {
            s.erase(0, s.find_first_not_of('0'));
            hash[s] += 1;
        }
        
        return hash.size();
    }
};