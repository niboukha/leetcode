class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        map<string, int>    hash;
        vector<string>      ans;
        string              str;

        for(int i = 0; i < 10; i++)
            str += s[i];
        hash[str] += 1;
        for(int i = 10; i < s.size(); i++)
        {
            str = str.substr(1);
            str += s[i];
            hash[str] += 1;
            if (hash[str] == 2)
                ans.push_back(str);
        }
        return ans;
    }
};