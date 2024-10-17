class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size();

        while(left < right and right > 1)
        {
            if (nums[left] == 0)
            {
                nums.push_back(nums[left]);
                nums.erase(nums.begin() + left);
                right--;
            }
            else
                left++;
        }
    }
};