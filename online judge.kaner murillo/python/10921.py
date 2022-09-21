#https://onlinejudge.org/external/109/10921.pdf
#10921

from sys import stdin

cadena  = stdin.readline().rstrip('\n')
dic = {"ABC": '2', "DEF": '3', "GHI": '4', "JKL": '5', "MNO": '6', "PQRS": '7', "TUV": '8', "WXYZ": '9'}

while cadena != "":

    cad = []

    for i in cadena:

        if i == '-' or i == '1' or i == '0':

            cad.append(i)
        
        else:

            for n in dic:

                if i in n:
                    cad.append(dic[n])

    print("".join(cad))

    cadena = stdin.readline().rstrip()