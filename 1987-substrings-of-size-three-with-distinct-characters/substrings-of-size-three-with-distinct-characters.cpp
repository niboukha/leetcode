class Solution {
public:
    int countGoodSubstrings(string s)
    {
        int res = 0;
        int k = 3;

        for (int i = 0; i < s.size(); i++)
        {
            // cout << i << " " << i + k - 1<< "\n";
            if (i + k - 1 < s.size() and check(s.substr(i, k)) == true)
                res += 1;
        }
        return res;
    }


    bool check(string s)
    {
        // cout << s << "\n";
        vector<int> hash(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i] - 97] == 0)
                hash[s[i] - 97] += 1;
            else
            {
                hash.clear();
                break;
            }
        }
        if (!hash.empty())
            return true;
        return false;
    }
};