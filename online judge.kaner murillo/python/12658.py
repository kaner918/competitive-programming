#https://onlinejudge.org/external/126/12658.pdf
#12658

from sys import stdin

numbers = int(stdin.readline())

table = []

for i in range(5):

    table.append(stdin.readline().strip())

flag1, flag2, flag3 = False, False, False
position = 1
position2 = 2
cad = []

for i in range(numbers):

    count = 0
    count2 = 0

    for n in range(5):

        if table[n][position] == "*":

            count+=1
    
        if table[n][position2] == "*":

            count2+=1
    
    if count == 5:

        cad.append('1')
    
    elif count2 == 5:

        cad.append('3')
    
    else:

        cad.append('2')

    position+=4 
    position2+=4

print("".join(cad))