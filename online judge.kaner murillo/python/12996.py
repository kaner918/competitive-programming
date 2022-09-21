#https://onlinejudge.org/external/129/12996.pdf
#12996

from sys import stdin

casos = int(stdin.readline())

for i in range(1,casos+1):

    persona = [int(x) for x in stdin.readline().split()]

    mangos = [int(x) for x in stdin.readline().split()]
    mangosComer = [int(x) for x in stdin.readline().split()]

    ans = True
    contador = 0
    n = 0

    while n < persona[0] and ans == True:

        if contador>persona[1] or mangos[n] > mangosComer[n]:
            ans = False

        contador+=mangos[n]

        n+=1
    
    if ans == True and contador<=persona[1]:

        print(f"Case {i}: Yes")
    
    else:

        print(f"Case {i}: No")