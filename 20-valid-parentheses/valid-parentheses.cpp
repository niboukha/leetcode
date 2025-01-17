class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == '(' or s[i] == '[' or s[i] == '{'))
            {
                st.push(s[i]);
                continue;
            }
            if (s[i] == ')' and (st.size() >= 1 and st.top() != '('))
                return false;
            else if (s[i] == ']' and (st.size() >= 1 and st.top() != '['))
                return false;
            else if (s[i] == '}' and (st.size() >= 1 and st.top() != '{'))
                return false;
            else if (!st.empty())
                    st.pop();
            else
                return false;
        }
        if (st.empty())
            return true;
        return false;
    }
};