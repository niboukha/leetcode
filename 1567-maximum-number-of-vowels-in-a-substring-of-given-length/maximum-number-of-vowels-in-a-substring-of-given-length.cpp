class Solution{
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

            for(int i = k; i < s.length(); i++)
            {
                    numberOfVowels = numberOfVowels - is_vowel[s[i - k]] + is_vowel[s[i]];
                    ans = max(ans, numberOfVowels);
            }
            return ans;
        }
};
