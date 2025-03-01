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
        
        # for i in range(len(nums)-1):
        #     for j in range(i+1,len(nums)):
        #         if nums[i]+nums[j] == target:
        #             return (i,j)

        # return



         # approach 2 using two pointer approach
        nums.sort() # soring the array 
        left, right = 0, len(nums)-1

        while left < right:
            sum = nums[left]+nums[right]

            if sum == target:
                return (left,right)
            elif sum < target:
                left +=1
            elif sum >target:
                right -=1
        return
    
        