class Solution {
public:
    int compress(vector<char>& chars)
    {
        string  s;
        int     left = 0;
        int     right = 0;

        while (right < chars.size())
        {
            if (chars[left] == chars[right])
                right++;
            if (right == chars.size() or chars[left] != chars[right])
            {
                s += chars[left];
                if (right - left > 1)
                    s += to_string(right - left);
                left = right;
            }
        }
        for (int i = 0; i < s.length(); i++)
            chars[i] = s[i];
        return s.length();
    }
};
