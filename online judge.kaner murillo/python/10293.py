#https://onlinejudge.org/external/102/10293.pdf
#10293

from sys import stdin 

line = stdin.readline().strip()

while line != "":

    dic = {}
    flag = False
    cad = []

    while line != "#":

        for i in range(len(line)):

            if((ord('a') <= ord(line[i]) <= ord('z')) or (ord('A')<= ord(line[i])<= ord('Z'))):

                cad.append(line[i])
            
            elif line[i] != "-" and line[i]!= "'" and len(cad) > 0:

                if len(cad) not in dic:

                    dic[len(cad)] = 1
                
                else:

                    dic[len(cad)]+=1
                
                cad = []

        if len(cad) > 0 and line[-1] != "-" and line[-1] != "'":

            if len(cad) not in dic:

                dic[len(cad)] = 1
            
            else:

                dic[len(cad)]+=1

            cad = []
            
        line = stdin.readline().strip()

    sor = sorted(dic.items())

    for i in sor:
        print(i[0], i[1]) 

    print()
    line = stdin.readline().strip()
