#11678
#https://onlinejudge.org/external/116/11678.pdf

from sys import stdin

def main():

    size = [int(x) for x in stdin.readline().split()]

    while size != [0, 0]:

        boy1 = set([int(x) for x in stdin.readline().split()])
        boy2 = set([int(x) for x in stdin.readline().split()])

        dif = boy1 ^ boy2 #diferencia simetrica

        if len(boy1 & dif) <= len(boy2 & dif):

            print(len(boy1&dif))

        else:

            print(len(boy2&dif))
            
        size = [int(x) for x in stdin.readline().split()]

main()