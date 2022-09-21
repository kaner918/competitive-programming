#https://onlinejudge.org/external/112/11233.pdf
#11233

from sys import stdin

irregular, words = [int(x) for x in stdin.readline().split()]
dic = {}

for i in range(irregular):

    duple = stdin.readline().split()

    dic[duple[0]] = duple[1]

for i in range(words):

    word = list(stdin.readline().strip())

    if "".join(word) in dic:

        print(dic["".join(word)]) 
    
    elif len(word) > 1 and word[-1] == "y" and word[-2] != "a" and word[-2] != "e" and word[-2] != "i" and word[-2] != "o" and word[-2] != "u":
        word[-1] = "ies"
        print("".join(word))

    elif (word[-1] == "o" or word[-1] == "s" or word[-1] == "x") or (len(word) > 1 and((word[-1] == "h" and word[-2] == "c") or(word[-1] == "h" and word[-2] == "s"))):

        word.append("es")
        print("".join(word))

    else:
        word.append("s")   
        print("".join(word))
