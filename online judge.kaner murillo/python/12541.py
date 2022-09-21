#https://onlinejudge.org/external/125/12541.pdf
#12541

from sys import stdin 

cantidad  = int(stdin.readline().strip())

personas = []

for i in range(cantidad):

    personas.append(stdin.readline().split())

personas.sort(key= lambda x: (int(x[3]), int(x[2]), int(x[1])))

print(personas[-1][0])
print(personas[0][0])
