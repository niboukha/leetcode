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
                // cout<<hash[s[right]]<<" "<<s[right]<<" "<<right<<"\n";
                right++;
            }
            else
            {
                ans = max(ans, right - left);
                // cout << ans << " " << right << "-" << left << "\n";
                hash.assign(128, 0);
                left++;
                right = left;
            }
        }
        if (left < right)
        {
            // cout << ans << "\n";
            ans = max(ans, right - left);
        }
        return ans;
    }
};