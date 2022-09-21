#https://onlinejudge.org/external/128/12854.pdf
#12854

from sys import stdin

conector1 = stdin.readline().split()

while conector1 != []:

    conector2 = stdin.readline().split()
    ans = True
    i = 0

    while i < 5 and ans == True:

        if conector1[i] == conector2[i]:
            ans = False

        i+=1 
    
    if ans == True:
        print("Y")
    
    else:
        print("N")
    
    conector1 =stdin.readline().split()