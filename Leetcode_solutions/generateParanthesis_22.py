class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        stack = []
        res = []

        def backtrack(openN, closedN):
            print(f"Called: backtrack(openN={openN}, closedN={closedN}, stack={stack})")  # Debugging

            if openN == closedN == n:
                res.append("".join(stack))
                print(f"Added to result: {''.join(stack)}")  # Track when we add a valid sequence
                return
            
            if openN < n:
                stack.append("(")
                print(f"Added '(': {stack}")  # Track adding '('
                backtrack(openN + 1, closedN)
                stack.pop()
                print(f"Backtracked after '(': {stack}")  # Track backtracking after '('

            if closedN < openN:
                stack.append(")")
                print(f"Added ')': {stack}")  # Track adding ')'
                backtrack(openN, closedN + 1)
                stack.pop()
                print(f"Backtracked after ')': {stack}")  # Track backtracking after ')'

        backtrack(0, 0)
        return res


# Test
solution = Solution()
print(solution.generateParenthesis(2))
