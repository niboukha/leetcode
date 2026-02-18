class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        i = 0
        n = len(words)

        while i < n:
            line_words = [words[i]]
            line_length = len(words[i])
            i += 1

            while i < n and len(words[i]) + line_length + 1 <= maxWidth:
                line_length += len(words[i]) + 1
                line_words.append(words[i])
                i += 1
            
            if i == n or len(line_words) == 1:
                line = ' '.join(line_words)
                line += ' ' * (maxWidth - len(line))
                ans.append(line)
            else:
                spaces = maxWidth - sum(len(word) for word in line_words)
                gaps = len(line_words) - 1

                spaces_per_gap, extra = divmod(spaces, gaps)
                justified_line = []
                for idx in range(gaps):
                    justified_line.append(line_words[idx])
                    justified_line.append(' ' * (spaces_per_gap + (1 if idx < extra else 0)))
                justified_line.append(line_words[-1])
            
                ans.append(''.join(justified_line))



        return ans
