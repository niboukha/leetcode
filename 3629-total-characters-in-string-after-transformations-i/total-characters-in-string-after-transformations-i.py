class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = (10**9) + 7
        sfreq = [0] * 26
        
        for char in s:
            sfreq[ord(char) - ord('a')] += 1

        while t > 0:
            nfreq = [0] * 26
            for i in range(26):
                if i == 25:
                    nfreq[(i + 1) % 26] += (sfreq[i] % mod)
                    nfreq[(i + 2) % 26] += (sfreq[i] % mod)
                else:
                    nfreq[i + 1] += (sfreq[i] % mod)
            sfreq = nfreq
            t -= 1

        return sum(sfreq) % mod
