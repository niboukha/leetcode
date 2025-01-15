class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        std::stack<int> s;
        int             a, b;

        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].find_first_not_of("0123456789") != std::string::npos && tokens[i].size() == 1)
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                switch (tokens[i][0])
                {
                    case '+':
                        s.push(a + b);
                        break;
                    case '-':
                        s.push(b - a);
                        break;
                    case '*':
                        s.push(a * b);
                        break;
                    case '/':
                        s.push(b / a);
                    }
            }
            else
                s.push(stoi(tokens[i]));
        }
        return (s.top());
    }
};