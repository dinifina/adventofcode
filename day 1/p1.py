class Solution:
    # Opens file "input.txt" in read mode
    file = open("input.txt", "r")
    sum = 0;
    
    # Reads line by line in file
    for x in file:
        i = ""
        j = ""
        count = 0;
        
        for y in x:
            if y.isdigit():
                i = y
                break
        
        reversed = x[::-1]
        
        for y in reversed:
            if y.isdigit():
                j = y
                break
                
        s = i + j
        num = int(s)
        print(num)
        sum += num
        
    print(sum)