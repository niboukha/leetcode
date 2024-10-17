class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        auto it = nums.begin();
        int left = 0;
        int right = nums.size();

        while(left < right and right > 1)
        {
            if (nums[left] == 0)
            {
                nums.push_back(nums[left]);
                cout << left << "\n";
                nums.erase(nums.begin() + left);
                right--;
            }
            else
                left++;
        }
    }
};