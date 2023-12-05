import re

class Solution:
    file = open("input.txt", "r")
    sum = 0

    def check(colour, input):
        sets = re.split('[:,;]', input)
        colSet = [i for i in sets if colour in i]
        quant = [int(re.search(r'\d+', i).group()) for i in colSet]
        
        return max(quant)
    
    def getID(input):
        sets = re.split('[:,;]', input)
        return int(re.search(r'\d+', sets[0]).group())

    for ln in file:
        pow = check('red', ln) * check('green', ln) * check('blue', ln)
        sum += pow
    
    print(sum)