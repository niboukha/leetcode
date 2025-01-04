class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int res = 0;

        int left = 0;
        int right = nums.size() - 1;
        int k = 0;

        if (nums.size() == 1 and nums[0] == val)
            return res;

        while(left <= right)
        {
            cout << nums[left] << " " << nums[right] << "\n";
            // if (left < right and nums[left] == val and nums[right] == val)
            // {
            //     left++;
            //     right--;
            //     res++;
            //     continue;
            // }
            
            if (nums[right] == val)
            {
                cout << nums[right] << "\n";
                right--;
                res++;
                continue;
            }
            if (nums[left] == val and nums[right] != val)
            {
                swap(nums[left], nums[right]);

                left++;
                right--;
                res++;
                cout << res << "\n";

            }
            else
            {
                left++;
            }
        }

        for (int i = 0 ; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << "\n";
        cout << res << "\n";
        return nums.size() - res;
    }
};

