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
            cout << left << " " << right << "\n";
            if (right < nums.size())
            {
                set.insert(nums[right]);
                miN = *set.begin();
                maX = *std::prev(set.end());
            //     std::cout << nums[right] << " " << nums[left] << "\n";
            //     std::cout << miN  << "+" << maX << "\n";
            }
            else
                break;
            if (abs(maX - miN) <= limit)
            {
                if (right < nums.size())
                    right++;
                // else
                //     left++;
                res = max(res, right - left);
            }
            else
            {
                auto it = set.find(nums[left]);
                if (it != set.end()) {
                    set.erase(it);
                }
                left++;
                if (right < nums.size())
                    right++;

            }
        }
        return res;
    }
};