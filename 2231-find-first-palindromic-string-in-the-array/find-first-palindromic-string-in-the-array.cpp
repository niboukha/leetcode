class Solution {
public:
    string firstPalindrome(vector<string>& words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            int left = 0, right = words[i].size() - 1;
            while (left < right)
            {
                if (words[i][left] != words[i][right] and i < words.size())
                    break;
                left++;
                right--;
            }
            if (left == right or (left == right + 1 and !(words[i].size() % 2)))
                return words[i];
        }
        return "";
    }
};