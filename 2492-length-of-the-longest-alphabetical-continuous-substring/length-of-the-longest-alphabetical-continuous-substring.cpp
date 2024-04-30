class Solution {
public:
    int longestContinuousSubstring(string s)
    {
        int ans = 0;
        int left = 0;
        int right = 0;
        int cmt = 0;

        while (right < s.length())
        {
            if (s[left] + cmt == s[right])
                right++, cmt++;
            else
            {
                ans = max(ans, cmt);
                cmt = 0;
                left = right;
            }
        }
        if (left < right)
            ans = max(ans, cmt);
        return ans;
    }
};