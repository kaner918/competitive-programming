#https://onlinejudge.org/external/6/644.pdf
#644

from sys import stdin

line = stdin.readline().strip()
counter = 1

while line != "":

    codes = [line]
    higer = len(line)
    ans = True

    while line != "9":

        line = stdin.readline().strip()
        
        if line in codes:
            ans = False

        if len(line) > higer:

            higer = len(line)
        
        codes.append(line)

    codes.sort(key = lambda x: (len(x)))

    i = 0
    n = 0

    if ans == True:
        
        while i < len(codes) and ans == True:

            if(len(codes[i]) < higer):

                n = i + 1

                while n < len(codes) and ans == True:

                    if codes[i] == codes[n][0:len(codes[i])]:

                        ans = False

                    n+=1
            
            i+=1

    if ans == True:

        print(f"Set {counter} is immediately decodable")
    
    else:

        print(f"Set {counter} is not immediately decodable")

    line = stdin.readline().strip()
    counter+=1
