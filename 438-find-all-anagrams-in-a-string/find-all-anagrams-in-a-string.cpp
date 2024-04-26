class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> hashS(26, 0);
        vector<int> hashP(26, 0);
        vector<int> ans;    

        for(int i = 0; i < p.size(); i++)
            hashP[p[i] - 'a'] += 1;
        
        for(int i = 0; i < p.size() and i < s.size(); i++)
            hashS[s[i] - 'a'] += 1;
        if (hashS == hashP)
            ans.push_back(0);
        for(int i = p.length(); i < s.size(); i++)
        {
            // for(int i = 0; i < hashP.size(); i++)
            // {
            //     cout << hashS[i] << " " << hashP[i] << "\n";
            // }
            cout << i << " " << s[i] << "\n";
            hashS[s[i] - 'a'] += 1;
            hashS[s[i - p.length()] - 'a'] -= 1;
            if (hashS == hashP)
                ans.push_back(i - p.length() + 1);   
        }
        return ans;
    }
};