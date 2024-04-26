class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> hash(26, 0);
        vector<int> h(26, 0);
        int left = 0;
        int right = 0;
        string s;
        
        for (int i = 0; i < s1.size(); i++)
            hash[s1[i] - 'a'] += 1;

        for (int i = 0; i < s1.size() and i < s2.size(); i++)
            h[s2[i] - 'a'] += 1;

        if (h == hash)
            return true;
        for (int i = s1.length(); i < s2.size(); i++)
        {
        //    cout << i << " " << s2[i] << "\n";
        //     for(int i = 0; i < h.size(); i++)
        //         cout << h[i]<<" ";
            // cout << "\n";
            h[s2[i] - 'a'] += 1;
            h[s2[i - s1.length()] - 'a'] -= 1;
            if (h == hash)
                return true;
    
        }
        return false;
    }
};
