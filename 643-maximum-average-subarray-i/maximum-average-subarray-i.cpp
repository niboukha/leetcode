class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double  avrg = 0;
        double  sum = 0;
        
        for(int i = 0; i < k; i++)
            sum += nums[i];
        avrg = sum / k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + k < nums.size())
                sum = sum - nums[i] + nums[i + k];
            avrg = max (sum / k, avrg);
        }
        return (avrg);
    }
};