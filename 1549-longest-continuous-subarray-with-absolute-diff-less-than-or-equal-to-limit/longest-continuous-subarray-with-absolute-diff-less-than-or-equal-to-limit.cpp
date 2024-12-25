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
            set.insert(nums[right]);
            if (abs(*std::prev(set.end()) - *set.begin()) <= limit)
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
            if (right >= nums.size())
                break;
        }
        return res;
    }
};