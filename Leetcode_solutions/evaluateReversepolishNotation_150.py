class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        operators = {}

        for token in tokens:
            if token.lstrip('-').isdigit():
                stack.append(int(token))
            else:
                val1 = stack.pop()
                val2 = stack.pop()

                if token == "+":
                    stack.append(val2 + val1)
                elif token == "-":
                    stack.append(val2 - val1)
                elif token == "*":
                    stack.append(val2 * val1)
                elif token == "/":
                    stack.append(int(val2 / val1) if val2 % val1 == 0 else (val2 // val1) if (val2 > 0) == (val1 > 0) else (val2 // val1 + 1))
        return stack.pop()