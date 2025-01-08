class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int right1 = m - 1;
        int right2 = n - 1;
        int i = n + m - 1;

        while (right2 >= 0 and right1>= 0)
        {
            nums1[i] = max(nums1[right1], nums2[right2]);
            if (nums1[right1] >= nums2[right2])
            {
                nums1[right1] = 0;
                right1--;
            }
            else
            {
                nums2[right2] = 0;
                right2--;
            }    
            i--;
        }
        while (i >= 0 and right2 >= 0)
        {
            nums1[i] = nums2[right2];
            right2--;
            i--;
        }


    }
};