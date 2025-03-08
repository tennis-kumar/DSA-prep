class Solution:
    def trap(self, height: List[int]) -> int:
        
        # solution 1, O(n) space and memory using brute force

        # solution 2, O(1) memory approach two pointer approach

        if not height: return 0

        l, r = 0, len(height) - 1
        lMax, rMax = height[l], height[r]
        res = 0

        while l < r:
            if lMax < rMax:
                l += 1
                lMax = max(lMax, height[l])
                res += lMax - height[l]
            else:
                r -= 1
                rMax = max(rMax, height[r])
                res += rMax - height[r]
        
        return res