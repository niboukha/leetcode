class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int res = 0;
        int left = 0;
        int right = 0;
        int i = 0;
        while (left < haystack.size())
        {
            res = right;
            while (i < needle.size())
            {
                if (haystack[right] != needle[i])
                    break;
                else if (i == needle.size() - 1)
                    return res;
                right++;
                i++;
            }
            i = 0;
            left++;
            right = left;
        }
        return -1;
    }
};