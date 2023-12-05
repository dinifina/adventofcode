import re

class Solution:
    file = open("input.txt", "r")
    sum = 0
    
    def check(colour, input):
        maxCubes = {
            "red": 12,
            "green": 13,
            "blue": 14
        }
        
        sets = re.split('[:,;]', input)
        colSet = [i for i in sets if colour in i]
        
        for x in colSet:
            if int(re.search(r'\d+', x).group()) > maxCubes[colour]: return False
        
        return True
    
    def getID(input):
        sets = re.split('[:,;]', input)
        return int(re.search(r'\d+', sets[0]).group())

    for ln in file:
        if check('red', ln) and check('blue', ln) and check('green', ln):
            sum += getID(ln)
    
    print(sum)