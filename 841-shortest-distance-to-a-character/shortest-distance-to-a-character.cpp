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
            // cout << i << " " << left << " " << right << "\n";
            if (left > 0 and s[left] != c)
            {
                // cout << "left -> " << left <<  "\n";
                left--;
            }
            if (right < s.size() and s[right] != c)
            {
                // cout << "right -> " << right <<  "\n";
                right++;
            }
            if (s[i] == c)
            {
                // cout << "i -> " << i << "\n";
                answer[i] = 0;
                i++;
                left = i;
                right = i;
            }
            else if (s[left] == c and s[right] == c)
            {
                cout << "s[left], s[right] => " << i << " " << abs(i - left) << " " << abs(i - right) << "\n";
                answer[i] = min (abs(i - left), abs(i - right));
                i++;
                left = i;
                right = i;
            }
            else if (s[left] == c)
            {
                cout << "s[left] => " << s[left] << " " << i << "\n";
                answer[i] = abs(i - left);
                i++;
                left = i;
                right = i;
            }
            else if (s[right] == c)
            {
                cout << "s[right] => " << s[right] << " " << i << "\n";
                answer[i] = abs(i - right);
                i++;
                left = i;
                right = i;
            }
        }
        return answer;
    }
};
