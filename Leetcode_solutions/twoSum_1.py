class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        # approach 1 brute force method
        # for i in range(len(nums)-1):
        #     for j in range(i+1,len(nums)):
        #         if nums[i]+nums[j] == target:
        #             return (i,j)

        # return

        
        # approach 2 using two pointer approach
        # nums.sort() # soring the array 
        # left, right = 0, len(nums)-1

        # while left < right:
        #     sum = nums[left]+nums[right]

        #     if sum == target:
        #         return (left,right)
        #     elif sum < target:
        #         left +=1
        #     elif sum >target:
        #         right -=1
        # return


        # approach 3 using hashmap/dictonary

        index_map = {}

        for i,num in enumerate(nums):
            complement = target - num

            if complement in index_map:
                return [index_map[complement],i]
            index_map[num] = i
        
        return