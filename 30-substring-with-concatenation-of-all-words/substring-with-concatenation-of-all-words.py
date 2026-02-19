class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # If input string or list of words is empty, return empty result
        if not s or not words:
            return []

        ans = []
        hash_words = Counter(words)

        # All words have the same length
        word_len = len(words[0])              
        total_words = len(words)

        # We check starting at each possible word offset (0 .. word_len-1)
        # because valid concatenations must align with word boundaries.
        for l in range(word_len):
            # Reset window state for this offset
            hash_concate = {}
            left = l          # 'left' pointer of the sliding window
            count = 0         # how many valid words seen in current window

            # Slide right pointer in steps of word_len
            # so that every 'word' we read is exactly word_len characters.
            for r in range(l, len(s) - word_len + 1, word_len):
                word = s[r : r + word_len]  # extract next word‑length substring

                # If this word is part of the words we want…
                if word in hash_words:
                    # Add it to our current count map
                    hash_concate[word] = hash_concate.get(word, 0) + 1
                    count += 1

                    # If this word occurs more times than allowed,
                    # shrink the window from the left until it's valid
                    while hash_concate[word] > hash_words[word]:
                        left_word = s[left : left + word_len]
                        hash_concate[left_word] -= 1
                        count -= 1
                        left += word_len

                    # If we have the correct number of words,
                    # then the substring starting at 'left' is valid
                    if count == total_words:
                        ans.append(left)

                        # Move the left pointer one word to make room for new matches
                        left_word = s[left : left + word_len]
                        hash_concate[left_word] -= 1
                        count -= 1
                        left += word_len

                else:
                    # If we find a word not in the list,
                    # reset the current window entirely
                    hash_concate.clear()
                    count = 0
                    left = r + word_len

        return ans
