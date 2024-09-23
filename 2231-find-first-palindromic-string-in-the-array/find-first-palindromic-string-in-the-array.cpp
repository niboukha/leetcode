class Solution {
public:
    string firstPalindrome(vector<string>& words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            int left = 0, right = words[i].size() - 1;
            if (words[i].size() == 1 or(words[i].size() == 2 and words[i][0] == words[i][1]))
                return words[i];   
            while (left < right)
            {
                if (words[i][left] != words[i][right] and i < words.size())
                    break;
                left++;
                right--;
            }
            cout<< words[i] << " " << left  << " " << right << "\n";
            if (left == right or (left == right + 1 and !(words[i].size() % 2)))
                return words[i];
        }
        return "";
    }
};