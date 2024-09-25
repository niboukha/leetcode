class Solution {
public:
    int characterReplacement(string s, int k)
    {
        map<char, int> hash;
        int res = 0;
        int left = 0;
        int right = 0;
        int maxValue = 0;
        
        while (right < s.size())
        {
            hash[s[right]] += 1;
            maxValue = max(maxValue, hash[s[right]]);
            while((right - left + 1) - maxValue > k)
            {
                hash[s[left]] -= 1;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }

};
