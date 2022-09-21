#https://onlinejudge.org/external/108/10815.pdf
#10815

from sys import stdin

words = set()

line = stdin.readline().lower()

while line != "":

    i = 0
    cad = []
    while i < len(line)-1:

        if ord('a') <= ord(line[i]) <= ord('z'):
            cad.append(line[i])

        elif (ord('a') > ord(line[i]) or ord('z') < ord(line[i])) and len(cad) != 0:

            words.add("".join(cad))
            cad = []         

        i+=1

    if len(cad) != 0:
        words.add("".join(cad))

    line = stdin.readline().lower()

words = list(words)
words.sort()

for i in words:
    print(i) 