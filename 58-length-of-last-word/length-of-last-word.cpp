class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int right = s.size() - 1;
        int left = s.size() - 1;
        // if (s.size() == 1)
        //     return 1;
        while(left >= 0 and s[left] == ' ')
        {
            left--;
            right--;
        }

        while (left >= 0 and s[left] != ' ')
            left--;
        return right - left;
    }
};