class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int res = 0;
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {   
            if (nums[right] == val)
            {
                right--;
                res++;
            }
            else if (nums[left] == val and nums[right] != val)
            {
                swap(nums[left], nums[right]);

                left++;
                right--;
                res++;

            }
            else
                left++;
        }
        return nums.size() - res;
    }
};

