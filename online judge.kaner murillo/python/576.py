#https://onlinejudge.org/external/5/576.pdf
#576

from sys import stdin

line = stdin.readline().strip()
letters = ["a", "e", "i", "o", "u", "y"]

while line != "e/o/i":

    position = 1
    counter = 0
    flag = False
    ans = True
    i = 0

    while i <len(line)+1 and ans == True:
        
        if(i<len(line) and line[i] != "/" ):

            if(i>0 and line[i] in letters and line[i-1] not in letters) or (i == 0 and line[i] in letters):

                counter+=1
        
        else:

            if(position == 1 and counter != 5):
                ans = False
            
            elif(position == 2 and counter != 7):
                ans = False

            elif(position == 3 and counter != 5):
                ans = False
            
            else:
                counter = 0
                position+=1
        i+=1
    
    if ans == True:

        print("Y")
    
    else:

        print(position)
    
    line = stdin.readline().strip()