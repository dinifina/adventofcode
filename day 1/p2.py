class Solution:
    file = open("input.txt", "r");
    sum = 0;
    
    def firstNum(list, line):
        tempDict = {};
        for num in list:
            if line.find(num) != -1:
                tempDict[line.index(num)] = num
              
        return tempDict[min(tempDict.keys())]
    
    def lastNum(list, line):
        tempDict = {};
        for num in list:
            if line.rfind(num) != -1:
                tempDict[line.rindex(num)] = num
            
        return tempDict[max(tempDict.keys())]
    
    
    numDict = {
        "one": "1",
        "two": "2",
        "three": "3",
        "four": "4",
        "five": "5",
        "six": "6",
        "seven": "7",
        "eight": "8",
        "nine": "9",
        "zero": "0"
    }
    
    numList = ["one", "1", "two", "2", "three", "3", "four", "4", "five", "5", "six", "6", "seven", "7", "eight"
               , "8", "nine", "9", "zero", "0"]
    
    for x in file:
        i = firstNum(numList, x) if firstNum(numList, x).isdigit() else numDict[firstNum(numList, x)]
        j = lastNum(numList, x) if lastNum(numList, x).isdigit() else numDict[lastNum(numList, x)]
        
        calVal = i + j
        sum += int(calVal)
    
    print(sum)
        