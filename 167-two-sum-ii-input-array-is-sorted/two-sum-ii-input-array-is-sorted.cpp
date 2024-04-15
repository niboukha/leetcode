class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> arrOfIndex;
        int         left = 0;
        int         right = numbers.size() - 1;
        int         sum;

        while (left < right)
        {
            sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                arrOfIndex.push_back(left + 1);
                arrOfIndex.push_back(right + 1);
                break;
            }
            if (sum > target)
                right--;
            else
                left++;
        }
        return arrOfIndex;
    }
};