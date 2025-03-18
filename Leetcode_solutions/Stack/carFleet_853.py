class Solution(object):
    def carFleet(self, target, position, speed):
        pair = sorted(zip(position, speed), reverse=True)  # Sort by position descending
        stack = []
        for p, s in pair:
            time = (target - p) / float(s)  # Compute time to reach target
            if stack and time <= stack[-1]:  # If current car reaches before or at the same time, merge
                continue
            stack.append(time)  # Add a new fleet
        return len(stack)
