#https://onlinejudge.org/external/132/13275.pdf
#13275

from sys import stdin

casos = int(stdin.readline().strip())

for n in range(casos):

    cumple = [int(x)for x in stdin.readline().rstrip('\n').split()]

    if cumple[1] == 2 and cumple[0]>28:

        print(f"Case {n+1}: {(cumple[3]//4 -cumple[2]//4) + ((cumple[3]//400 -cumple[2]//400)) - ((cumple[3]//100 -cumple[2]//100 ))}")

    else:
        print(f"Case {n+1}: {cumple[3]-cumple[2]}")