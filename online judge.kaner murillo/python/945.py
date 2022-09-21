#https://onlinejudge.org/external/9/945.pdf
#945

from sys import stdin

containers = stdin.readline()

while len(containers) > 0:

    higer = 0
    dic = {}
    lista = []
    packages = []
    ans = True
    n = 0
    separator = []
    numbers = []
    sum = 0
    sum2 = 0
    sum3 = 0

    for i in range(int(containers)):

        dic[i] = int(stdin.readline())
        lista.append([])

    stdin.readline()
    sizePackages = int(stdin.readline())

    for i in range(sizePackages):

        packages.append(int(stdin.readline()))
    
    while n < len(packages):

        container = 0

        for i in range(1,int(containers)):

            if len(lista[i]) < len(lista[container]):

                container = i
            
            elif len(lista[i]) == len(lista[container]):
                
                if dic[i] > dic[container]:

                    container = i
                
                elif dic[i] == dic[container]: 

                    if i < container:

                        container = i            
        
        if dic[container] >= packages[n] and ans == True:

            dic[container]-=packages[n]
            lista[container].append(packages[n])
            sum+= packages[n]

            if len(lista[container]) > higer:

                higer = len(lista[container])

        else:

            ans = False
            sum2+=packages[n]

        n+=1

    for i in range(higer, 0, -1):

        cad = []

        for n in range(len(lista)):

            if len(lista[n]) < i:

                cad.append(":")
            
            else:

                cad.append(str(lista[n][i-1]))
            
            if n < len(lista)-1:

                cad.append(" ")

        print("".join(cad))

    for i in range(1, int(containers)):

        separator.append("==")
        numbers.append(str(i)+" ")
        sum3+=dic[i-1]

    separator.append("=")
    numbers.append(str(len(lista)))
    sum3+=dic[int(containers)-1]

    print("".join(separator))
    print("".join(numbers))
    print()
    print(f"cargo weight: {sum}")
    print(f"unused weight: {sum3}")
    print(f"unloaded weight: {sum2}")

    containers = stdin.readline()

    if len(containers) > 0:

        containers = stdin.readline()

    if len(containers) > 1:

        print()