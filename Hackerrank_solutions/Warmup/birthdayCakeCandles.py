#!/bin/python3

import math
import os
import random
import re
import sys
#
# Complete the 'birthdayCakeCandles' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY candles as parameter.
#

def birthdayCakeCandles(candles):
    # Write your code here
    freq_dict = {}
    
    if not candles:
        return 0
    
    for candle in candles:
        freq_dict[candle] = freq_dict.get(candle,0)+1
        
    max_count = 0
    for count in freq_dict.values():
        max_count = max(count,max_count)
        
    return max_count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    candles_count = int(input().strip())

    candles = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(candles)

    fptr.write(str(result) + '\n')

    fptr.close()
