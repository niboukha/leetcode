class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector <string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string  s;
        map<string, int>    hash;

        for (size_t i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
                s += table[words[i][j] - 'a'];
            hash[s] += 1;
            s.clear();
        }
        return hash.size();
    }
};