#https://onlinejudge.org/external/112/11222.pdf
#11222

from sys import stdin

cases = int(stdin.readline())

for i in range(1,cases+1):

    player1 = [int(x) for x in stdin.readline().split()]
    player1.pop(0)
    player2 = [int(x) for x in stdin.readline().split()]
    player2.pop(0)
    player3 = [int(x) for x in stdin.readline().split()]
    player3.pop(0)

    higer  = 0
    problems = []

    problems.append(set(player1) - (set(player2) | set(player3)))

    if len(problems[-1]) > higer:
        higer = len(problems[-1])

    problems.append(set(player2) - (set(player1) | set(player3)))

    if len(problems[-1]) > higer:
        higer = len(problems[-1])

    problems.append(set(player3) - (set(player2) | set(player1)))

    if len(problems[-1]) > higer:
        higer = len(problems[-1])

    print(f"Case #{i}:")

    if higer > 0:

        for n in range(3):

            if len(problems[n]) == higer:

                aux  = list(problems[n])

                sor = sorted(aux)

                print(n+1, len(problems[n]), end=" ")

                for x in range(len(sor)-1):
                    
                    print(str(sor[x])+" ", end="")
                
                print(sor[-1])

    else:

        print(1,0)
        print(2,0)
        print(3,0)
