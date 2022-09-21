#https://onlinejudge.org/external/113/11321.pdf
#11321

from sys import stdin

cantidad, mod = [int(x) for x in stdin.readline().split()]

def comparar(a,b):

    ans = False

    if a%mod == b%mod:
        
        if a%2 == 0 and b%2 == 0:

            ans = a<b
        
        elif a%2 == 0 and b%2!= 0:

            ans = False
        
        elif a%2!=0 and b%2 == 0:
            
            ans = True

        else:
            ans = a > b

    else:

        ans = a>b

    return ans

while cantidad != 0 or mod != 0:

    lista = []

    for i in range(cantidad):

        lista.append(int(stdin.readline().strip()))

    lista.sort(comparar)

    print(cantidad, mod)

    for i in lista:
        print(i)
        
    cantidad, mod = [int(x) for x in stdin.readline().split()]

print(0,0)