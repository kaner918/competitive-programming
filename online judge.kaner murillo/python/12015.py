#https://onlinejudge.org/external/120/12015.pdf
#12015

from sys import stdin 

cases = int(stdin.readline().strip())

for i in range(1,cases+1):

    links = []
    mayor = '0'

    for n in range(10):

        link = stdin.readline().split()
        if int(link[1])>int(mayor):
            mayor = link[1]

        links.append(link)
    
    print(f"Case #{i}:")

    for n in range(10):

        if(links[n][1] == mayor):
            print(links[n][0])


