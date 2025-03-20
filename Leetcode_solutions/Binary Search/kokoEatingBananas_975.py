class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)
        optimal_speed = right

        while left <= right:
            mid_speed = (left + right) // 2
            required_hours = 0

            for pile in piles:
                required_hours += math.ceil(pile / mid_speed)

            if required_hours <= h:
                optimal_speed = min(optimal_speed, mid_speed)
                right = mid_speed - 1
            else:
                left = mid_speed + 1

        return optimal_speed