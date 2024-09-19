class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k)
    {
        vector<int> res(code.size(), 0);
        int sum = 0;

        int j = 0;
        if (k >= 0)
        {
            while (j < k)
            {
                sum += code[j];
                j++;
            }
            for (int i = code.size() - 1; i >= 0; i--)
            {
                res[i] = sum;
                sum = sum + code[i % code.size()] - code[(i + k) % code.size()];
            }
        }
        else
        {
            j = code.size() - 1;
            int a = k * -1;
            while (a != 0)
            {
                sum += code[j];
                j--;
                a--;
            }
            for (int i = 0; i < code.size(); i++)
            {
                if (i != 0)
                {
                    // int value = i + k - 1;
                    int mod = code.size();

                    int result = ((i + k - 1) % mod + mod) % mod;
                    res[i] = res[i - 1] + code[(i - 1) % code.size()] - code[result];
                }
                else
                    res[i] = sum;
            }
        }
        return res;

    }
};