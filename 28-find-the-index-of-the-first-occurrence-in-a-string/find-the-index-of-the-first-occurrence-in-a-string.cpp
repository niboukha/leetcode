class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int left = 0;
        int right = needle.size();

        while (left < haystack.size())
        {
            if(haystack.substr(left, needle.size()) == needle)
                return left;
            left++;
            if (right < haystack.size())
                right++;
        }

        return -1;
    }
};