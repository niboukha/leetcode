class Solution:
    def calculate(self, s: str) -> int:
        def helper(i: int) -> tuple[int, int]:
            stack = []
            num = 0
            sign = '+'

            while i < len(s):
                ch = s[i]

                if ch.isdigit():
                    num = num * 10 + int(ch)
                elif ch in "-+":
                    stack.append(num if sign == '+' else -num)
                    num = 0
                    sign = ch
                elif ch == '(':
                    num, i = helper(i + 1)
                elif ch == ")":
                    stack.append(num if sign == '+' else -num)
                    return sum(stack), i
                
                i += 1
            
            stack.append(num if sign == '+' else -num)
            return sum(stack), i

        result, _ = helper(0)
        return result