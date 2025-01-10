class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int maxp = 0;
        int left = 0;
        int right = left + 1;

        while (left < right)
        {
            if (right < prices.size() and prices[right] >= prices[left])
            {
                maxp = max(maxp, prices[right] - prices[left]);
                right++;
            }
            else if (right < prices.size() and right == left + 1)
            {
                left++;
                right++;
            }
            else
                left++;
        }
        return maxp;
    }
};