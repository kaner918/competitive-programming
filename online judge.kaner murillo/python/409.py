#https://onlinejudge.org/external/4/409.pdf
#409

from sys import stdin

counter = 1

dimentions = [int(x) for x in stdin.readline().split()]

while dimentions != []:

    higer = 0
    words = []

    for i in range(dimentions[0]):

        words.append(stdin.readline().strip().lower())

    list2 = []

    for i in range(dimentions[1]):

        duple = [0]
        duple.append(list(stdin.readline().strip()))
        cad = []

        for n in range(len(duple[1])):

            if ord('a') <= ord(duple[1][n].lower()) <= ord('z'):
                cad.append(duple[1][n].lower())
            
            elif len(cad) > 0:

                if "".join(cad) in words:
                    duple[0]+=1
                
                if duple[0] > higer:

                    higer = duple[0]

                cad = []

        if len(cad) > 0:

            if "".join(cad) in words:
                duple[0]+=1
            
            if duple[0] > higer:

                higer = duple[0]

        list2.append(duple)

    print(f"Excuse Set #{counter}")

    for i in list2:

        if i[0] == higer:
            print("".join(i[1]))

    dimentions = [int(x) for x in stdin.readline().split()]
    
    print()
    counter+=1