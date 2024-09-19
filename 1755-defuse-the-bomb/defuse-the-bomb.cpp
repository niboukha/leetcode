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
                    int value = i + k - 1;
                    int mod = code.size();

                    // Manually adjust to get the desired positive remainder
                    int result = (value % mod + mod) % mod; // This gives you the non-negative result.
                    // cout << result << "\n";
                    // if (result == 0) {
                    //     result = mod - 2; // Adjusting to get 3 when the result is 0
                    // } else {
                    //     result = (result - 1) % mod; // Getting 3 when the remainder is positive
                    // }
                    cout << res[i - 1] << " " << (i - 1) % code.size() << " " << (i + k - 1) << " " << result << "\n";
                    res[i] = res[i - 1] + code[(i - 1) % code.size()] - code[result];
                }
                else
                    res[i] = sum;
            }
        }
        return res;

    }
};