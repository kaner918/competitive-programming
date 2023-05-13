#https://onlinejudge.org/external/5/524.pdf
#524

from sys import stdin

primes = [True for _ in range(33)]

def criba_eratostenes(limit):

    global primes

    for i in range(2, int(limit**0.5)+1):

        if primes[i]:

            for j in range(i**2, limit+1, i):
                primes[j] = False

def solved(index, limit, res, res2):

    global primes
    
    if index==limit-1:
        
        if primes[res[0] + res[-1]]:

            print(' '.join(str(x) for x in res))

    else:

        for i in range(2, limit+1):

            if res2[i-1] == -1 and primes[res[index] + i]:

                res2[i-1] = 1
                res[index+1] = i
                solved(index+1, limit, res, res2) 
                res2[i-1] = -1
def main():

    size = stdin.readline()
    criba_eratostenes(32)

    counter = 1

    while size != "":
        size = int(size)
        print(f"Case {counter}:")
        counter+=1
        res = [-1 for x in range(size)]
        res2 = [-1 for x in range(size)]
        res[0] = 1

        solved(0,size,res, res2)
        size = stdin.readline()

        if size != "":
            print()

main()