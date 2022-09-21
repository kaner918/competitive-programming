#https://onlinejudge.org/external/100/10071.pdf
#10071


from sys import stdin

cadena = stdin.readline().strip()

while cadena!="":
    cadena2 = cadena.split()
    print(int(cadena2[0])*int(cadena2[1])*2)
    cadena = stdin.readline().strip()