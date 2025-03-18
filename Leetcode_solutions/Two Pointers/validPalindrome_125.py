class Solution(object):

    def alphaNum(self,c):
        return ((ord('A') <= ord(c) <= ord('Z')) or
           (ord('a') <= ord(c) <= ord('z')) or
           (ord('0') <= ord(c) <= ord('9')))

    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # solution 1
        # newStr = ""
        # for c in s:
        #     if c.isalnum():
        #         newStr += c.lower()
        # return newStr == newStr[::-1]




        #solution two using two pointers

        l,r = 0, len(s) - 1

        while l < r:

            while l < r and not self.alphaNum(s[l]):
                l += 1
            while r > l and not self.alphaNum(s[r]):
                r -= 1

            if s[l].lower() != s[r].lower():
                return False
            l,r = 1 + l, r - 1
        return True