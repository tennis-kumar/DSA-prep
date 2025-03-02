class Solution(object):
    
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        hash_map = {}
        result = []

        for arr_idx in range(len(strs)):
            substr = strs[arr_idx] # get current word
            
            substr = ''.join(sorted(substr)) # sort the current word

            # check if current word in hash_map
            if substr not in hash_map:
                hash_map[substr] = len(result) # Assign an index for this anagram group
                result.append([]) # create new group in result array/list

            #add the original word to the anagram group based on assigned index
            result[hash_map[substr]].append(strs[arr_idx]) 

        return result

# Time complexity: O(n*mlogm) where n is the number of words in the input list and m is the length of the longest word
# Space complexity: O(n) where n is the number of words in the input list