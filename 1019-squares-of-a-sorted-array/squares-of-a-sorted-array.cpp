class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> sortedPow;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            if (abs(nums[left]) < abs(nums[right]))
            {
                sortedPow.push_back(pow(nums[right], 2));
                right--;
            }
            else if (abs(nums[left]) >= abs(nums[right]))
            {
                sortedPow.push_back(pow(nums[left], 2));
                left++;
            }
        }
        left = 0;
        right = sortedPow.size() - 1;

        while (left <= right)
        {
            swap(sortedPow[left], sortedPow[right]);
            left++;
            right--;
        }
        return sortedPow;
    }
};