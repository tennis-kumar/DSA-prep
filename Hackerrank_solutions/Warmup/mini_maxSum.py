#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    # Write your code here
    total_sum = sum(arr)
    min_sum = float('inf')
    max_sum = float('-inf')
    
    for num in arr:
        current_sum = total_sum-num
        min_sum = min(min_sum, current_sum)
        max_sum = max(max_sum, current_sum)
    
    print( min_sum,max_sum)

if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
