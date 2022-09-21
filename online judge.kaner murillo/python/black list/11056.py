#https://onlinejudge.org/external/110/11056.pdf
#11056

from sys import stdin

size = stdin.readline().strip()

while size != "":

    pilots = []

    for i in range(int(size)):

       pilots.append(stdin.readline().split())
    
    input()

    pilots.sort(key = lambda x: (int(x[2]), int(x[4]), int(x[6]), x[0].lower()))

    counter = 1
    counter2 = 0

    print(f"Row {counter}")

    for i in pilots:

        if counter2 > 0 and counter2 % 2 == 0:
            counter+=1 
            print(f"Row {counter}")
            
        print(i[0])
        counter2+=1

    print()
    size = stdin.readline().strip()
        
    

