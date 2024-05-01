class Solution {
public:
    int percentageLetter(string s, char letter)
    {
        float  ans = 0;
        float   cmpt = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if (s[i] == letter)
                cmpt++;
        }
        ans = cmpt * 100 / s.size();
        return ans;
    }
};