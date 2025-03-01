class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        # approach 1 brute force
        # Time complexity is O(n^2) and space complexity is O(1)
        # This method is not efficient.
        
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j] == target:
                    return (i,j)

        return
    
        