#https://onlinejudge.org/external/118/11860.pdf
#11860

from sys import stdin

cases = int(stdin.readline())

for i in range(1, cases+1):

    dic = {}
    dicPosition = {}
    set1 = set()
    position = 1
    line = stdin.readline().strip()
    left = 1
    right = len(line)

    while line != "END":

        cad = []

        for n in range(len(line)):

            if ord('a') <= ord(line[n]) <= ord('z'):
                cad.append(line[n])
            
            elif len(cad) > 0:

                dic[position] = "".join(cad)

                if "".join(cad) not in dicPosition:
                    dicPosition["".join(cad)] = [position]
                
                else:
                    dicPosition["".join(cad)].insert(0,position)

                set1.add("".join(cad))
                cad = []
                position+=1
        
        if len(cad) > 0:
            dic[position] = "".join(cad)

            if "".join(cad) not in dicPosition:
                dicPosition["".join(cad)] = [position]
            
            else:
                dicPosition["".join(cad)].append(position)

            set1.add("".join(cad))
            position+=1

        line = stdin.readline().strip()
    
    for n in range(1, len(dic)):

        m = n
        set2 = set()

        while m < len(dic)+1 and len(set2) < len(set1):

            set2.add(dic[m])
            m+=1

        m-=1

        if len(set2) == len(set1) and abs(m-n) < abs(left-right):
            
            left = n
            right = m
    
    print(f"Document {i}: {left} {right}")
    print(sorted(dicPosition.items()))