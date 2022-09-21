#https://onlinejudge.org/external/130/13037.pdf
#13037

from sys import stdin

cases = int(stdin.readline())

for i in range(1, cases+1):

    possesses = [int(x) for x in stdin.readline().split()]

    set1 = set([int(x) for x in stdin.readline().split()])
    set2 = set([int(x) for x in stdin.readline().split()])
    set3 = set([int(x) for x in stdin.readline().split()])
    
    print(f"Case #{i}:")

    print(len(set1-(set2|set3)),len((set2&set3)-set1))
    print(len(set2-(set1|set3)),len((set1&set3)-set2))
    print(len(set3-(set2|set1)),len((set2&set1)-set3))

