class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        int left = 0;
        int right = 0;

        while (right < word.size())
        {
            if (word[right] != ch)
                right++;
            else
            {
                while (left < right)
                {
                    swap(word[right], word[left]);
                    left++;
                    right--;
                }
                return word;
            }
        }
        return word;
    }
};