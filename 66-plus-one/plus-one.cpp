class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int i = digits.size() - 1;
        for (; i >= 0; i--)
        {
            if (digits[i] != 9)
                break;
        }
        if (i == -1)
            i++;
        if (i != digits.size() - 1 or digits[i] == 9)
        {
            if (digits[i] == 9)
            {
                digits[i] = 1;
                i++;
                for (; i < digits.size(); i++)
                    digits[i] = 0;
                digits.push_back(0);
            }
            else
            {
                digits[i] += 1;
                i++;
                for (; i < digits.size(); i++)
                    digits[i] = 0;
            }
        }
        else
            digits[digits.size() - 1] += 1;
        return digits;
    }
};
