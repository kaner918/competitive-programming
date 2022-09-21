#https://onlinejudge.org/external/131/13148.pdf
#13148

from sys import stdin

number = int(stdin.readline())
numbers = [1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
47045881, 64000000, 85766121]

while number != 0:

    if number in numbers:
        print("Special")
    
    else:
        print("Ordinary")

    number = int(stdin.readline())