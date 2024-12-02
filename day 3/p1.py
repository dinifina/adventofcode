import numpy as np

class Solution:
    file = open("input.txt")
    sum = 0
    arr = np.array(file.readline())
    
    for ln in file:
        arr = np.vstack((arr, file.readline()))
    
    rows, cols = arr.shape
    symbols = set(symbol.lower() for symbol in ('*', '+', '-', '=', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')'))
    
    def searchRange(x, y):
    
    for y in cols:
        for x in rows:
            if arr[x][y].lower() in symbols:
                