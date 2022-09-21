#https://onlinejudge.org/external/131/13130.pdf
#https://www.udebug.com/UVa/13130
#13130

from sys import stdin 

casos = int(stdin.readline().strip())

for i in range(casos):

    escala = [int(x) for x in stdin.readline().split()]

    if escala[0]+1==escala[1] and escala[1]+1==escala[2] and escala[2]+1==escala[3] and escala[3]+1==escala[4]:
        print("Y")
    
    else:
        print("N")
    
            