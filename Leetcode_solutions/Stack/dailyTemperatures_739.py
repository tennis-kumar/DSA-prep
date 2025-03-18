class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        n = len(temperatures)
        res = [0] * n  # Initialize the result array with zeros
        stack = []  # Monotonic decreasing stack to store indices

        print(f"Initial Temperatures: {temperatures}")
        print(f"Initial Stack: {stack}\n")

        for i in range(n):
            print(f"Day {i}: Temperature = {temperatures[i]}")

            # Process the stack if the current temperature is greater than the one at the top index
            while stack and temperatures[i] > temperatures[stack[-1]]:
                prev_index = stack.pop()
                res[prev_index] = i - prev_index  # Store the difference of indices
                print(f"  Found warmer day for index {prev_index} ({temperatures[prev_index]}° -> {temperatures[i]}°)")
                print(f"  Updated res[{prev_index}] = {res[prev_index]}")

            stack.append(i)  # Push the current index onto the stack
            print(f"  Updated Stack: {stack}\n")

        print(f"Final Result: {res}")
        return res

# Test case
solution = Solution()
print(solution.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))
# Output: [1, 1, 4, 2, 1, 1, 0, 0]