class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        visited = set() # empty set to track visited values

        for num in nums:
            if num in visited: # if num already exists in the set, return true
                return True
            visited.add(num) # add num to set if not in set
        return False # return default false 
# Time complexity: O(n)
# Space complexity: O(n)