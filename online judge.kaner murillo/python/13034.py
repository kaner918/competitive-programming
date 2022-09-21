#https://onlinejudge.org/external/130/13034.pdf
#https://www.udebug.com/UVa/13034
#13034

from sys import stdin 

casos = int(stdin.readline().strip())

for i in range(1,casos+1):

    soluciones = stdin.readline().split()

    if '0' not in soluciones:
        print(f"Set #{i}: Yes")
    
    else:
        print(f"Set #{i}: No")
