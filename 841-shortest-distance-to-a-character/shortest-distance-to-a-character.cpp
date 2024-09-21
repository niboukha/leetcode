class Solution {
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> answer(s.size(), 0);

        int left = 0;
        int right = 0;
        int i = 0;
        while (i < s.size())
        {
            if (left > 0 and s[left] != c)
            {
                left--;
            }
            if (right < s.size() and s[right] != c)
            {
                right++;
            }
            if (s[i] == c or (s[left] == c and s[right] == c) or (s[left] == c) or (s[right] == c))
            {
                if (s[i] == c)
                    answer[i] = 0;
                else if (s[left] == c and s[right] == c)
                    answer[i] = min (abs(i - left), abs(i - right));
                else if (s[left] == c)
                    answer[i] = abs(i - left);
                else if (s[right] == c)
                    answer[i] = abs(i - right);
                i++;
                left = i;
                right = i;
            }
            
        }
        return answer;
    }
};
