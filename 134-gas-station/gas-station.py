class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_tank = 0
        current_tank = 0
        start = 0

        for i in range(len(gas)):
            net = gas[i] - cost[i]
            current_tank += net
            total_tank += net

            # If current segment can't reach next station,
            # reset and try the next station as new start
            if current_tank < 0:
                current_tank = 0
                start = i + 1

        # If total gas >= total cost, return start, else -1
        return start if total_tank >= 0 else -1