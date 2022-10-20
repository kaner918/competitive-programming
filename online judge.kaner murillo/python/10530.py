#https://onlinejudge.org/external/3/321.pdf
#321

from sys import stdin

def main():

    number = int(stdin.readline())
    dawn = 0
    up = 11

    while number != 0:

        res = stdin.readline().rstrip('\n')

        if res[-1] == "h" and number < up:

            up = number

        elif res[-1] == "w" and number > dawn:

            dawn = number

        elif res[-1] == "n":

            if number > dawn and number < up:

                print("Stan may be honest")
            
            else:

                print("Stan is dishonest")
            
            dawn = 0
            up = 11

        number = int(stdin.readline())

main()