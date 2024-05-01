class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int right = 0;
        int ans = 0;
        vector<int> hash(128, 0);

        while (right < s.size())
        {
            if (hash[s[right]] == 0)
            {
                hash[s[right]] += 1;
                right++;
            }
            else
            {
                ans = max(ans, right - left);
                hash[s[left]] -= 1;
                left++;
            }
        }
        if (left < right)
            ans = max(ans, right - left);
        return ans;
    }
};