// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k)
//     {
//         double   avrg = 0;
//         double   sum  = 0;
// 
//         for(int i = 0; i < k; i++)
//             sum += nums[i];
//         avrg = sum / k;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             // std::cout << avrg << "\n";
//             if (i + k < nums.size())
//                 sum = sum - nums[i] + nums[i + k];
//             avrg = max (sum / k, avrg);
//         }
//         return (avrg);
//     }
// };

class Solution
{
    public:
        int maxVowels(string s, int k)
        {
            vector<bool> is_vowel(127, 0);
            
            int ans            = 0;
            int numberOfVowels = 0;

            for ( int i = 0; i < 5; i++ )
                is_vowel["aeiou"[i]] = true;

            for (int i = 0; i < k; i++)
            {
                if (is_vowel[s[i]])
                    numberOfVowels++;
            }
            ans = max(ans, numberOfVowels);

            for(int i = 0; i < s.length(); i++)
            {
                if (i + k < s.length())
                {
                    if (is_vowel[s[i]])
                        numberOfVowels--;
                    if (is_vowel[s[i + k]])
                        numberOfVowels++;
                    ans = max(ans, numberOfVowels);
                }
            }
            return ans;
        }
};
