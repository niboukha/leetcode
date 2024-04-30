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
            {
                // cout<<s[left + cmt]<<" "<<s[right]<< " " << cmt << "\n";
                right++;
                cmt++;
            }
            else
            {
                ans = max(ans, cmt);
                // cout << ans <<" " <<  cmt <<" "<< right<<"\n";
                cmt = 0;
                left++;
            }
        }
        if (left < right)
        {
            ans = max(ans, cmt);
        }
            return ans;
    }
};