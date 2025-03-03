class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        ## Approach 1 - brute force, using stack

        # stack = []
        # for ch in s:
        #     if ch in ('(','{','['):
        #         stack.append(ch)
        #         continue
        #     elif ch in (')','}',']'):
        #         if not stack:
        #             return False
        #         elif (ch == ')' and stack[-1] != '('):
        #             return False 
        #         elif (ch == '}' and stack[-1] != '{'):
        #             return False
        #         elif (ch == ']' and stack[-1] != '['):
        #             return False
        #         stack.pop()
        
        # return (True if not stack else False)

        ## Approach 2 using dictionary and stack

        stack = []
        mapping = { '}':'{',')':'(',']':'[' }

        for ch in s:
            if ch in mapping.values(): # if opening bracket, push to stack
                stack.append(ch)
            elif ch in mapping:
                if not stack or stack[-1] != mapping[ch]: # mismatched or empty stack
                    return False
                stack.pop()
        
        return not stack # stack should be empty for vallid paranthesis