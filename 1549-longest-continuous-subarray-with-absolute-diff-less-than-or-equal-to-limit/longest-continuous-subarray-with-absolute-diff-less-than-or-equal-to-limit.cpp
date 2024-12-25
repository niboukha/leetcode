class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>   set;
        
        int res = 0;
        int left = 0;
        int right = 0;
        int maX, miN;
        while(left < nums.size())
        {
            if (right < nums.size())
            {
                set.insert(nums[right]);
                miN = *set.begin();
                maX = *std::prev(set.end());
            }
            else
                break;
            if (abs(maX - miN) <= limit)
                res = max(res, ++right - left);
            else
            {
                auto it = set.find(nums[left]);
                if (it != set.end()) {
                    set.erase(it);
                }
                left++;
                right++;
            }
        }
        return res;
    }
};