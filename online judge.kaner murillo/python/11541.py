#https://onlinejudge.org/external/115/11541.pdf
#11541

from sys import stdin

cases = int(stdin.readline())

for i in range(1,cases+1):

    cad = stdin.readline().strip()
    cad2 = []
    ans = True
    num = ""

    for n in range(len(cad)):

        if ord('A')<= ord(cad[n]) <= ord('Z') and ans == True:
            cad2.append(cad[n])

        elif ord('0')<= ord(cad[n])<= ord('9'):
            num+=cad[n]
            ans = False
        
        else:

            for m in range(int(num)-1):

                cad2.append(cad2[-1])

            cad2.append(cad[n])
            num = ""

    for m in range(int(num)-1):

        cad2.append(cad2[-1])

    code = "".join(cad2)

    print(f"Case {i}: {code}")
