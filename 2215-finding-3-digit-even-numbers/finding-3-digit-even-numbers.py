class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        ans = []
        countDigits = Counter(digits)

        for num in range(100, 1000, 2):
            div = [num // 100, (num // 10) % 10, num % 10]
            digitsInNumber = Counter(div)

            if all(countDigits[i] >= digitsInNumber[i] for i in digitsInNumber):
                ans.append(num)
        return ans


# Counter({2: 1, 1: 1, 3: 1, 0: 1})