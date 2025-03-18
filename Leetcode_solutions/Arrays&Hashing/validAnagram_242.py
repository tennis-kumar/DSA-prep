class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        """
        first approach, sort both the arrays, and if they are equal, we return true, else not
        
        string1 = sorted(s)
        string2 = sorted(t)
        return string1 == string2

        """

        """
        Second approach using Hashmap/dictonaty to store frequency of each character in the string
        """

        charCount = {} # hashmap (Dictionary) to store frequency of each character

        for ch in s:
            #the get(ch,0) checks if ch exists in charCount, if not, it adds it with default value 0
            charCount[ch] = charCount.get(ch,0)+1 # for each ch in s increment its count in charCount

        for ch in t:
            charCount[ch] = charCount.get(ch,0)-1 # for each ch in t decrement its count in charCount

        # if any character count !=0, it means both s and t have diff characters or frequencies
        for value in charCount.values():
            if value != 0:
                return False
        
        return True
# Time complexity: O(n)
# Space complexity: O(n)
# Approach: We use a hashmap to store the frequency of each character in the string s and t. 
# We increment the count of each character in s and decrement the count of each character in t. 
# If the count of any character is not equal to 0, we return False. Else we return True.