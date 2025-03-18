class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        #brute force O(n^2)
        
        # res = 0

        # for l in range(len(height)):
        #     for r in range(l+1, len(height)):
        #         area = (r - l) * min(height[l], height[r])
        #         res = max(res, area)

        # return res

        # two pointer approach

        l,r = 0,len(height) - 1
        res = 0

        while l < r:
            # formula area = width * height
            # width = difference b/w the distance of two indexes
            # height = common height b/w the two 
            area = (r - l) * min( height[l], height[r])
            res = max(res,area)

            if height[l] < height[r]:
                l += 1
            # elif height[l] > height[r]: # commenting this as the else block also does the same thing
            #     r -= 1
            else: # here we can either change the left or right as both of current values are equal
                r -= 1

        return res