#https://onlinejudge.org/external/3/321.pdf
#321

from sys import stdin

def main():

    number = int(stdin.readline())
    dawn = 1
    up = 10

    while number != 0:

        res = stdin.readline().rstrip('\n')

        if res[-1] == "h" and number < up:

            up = number-1

        elif res[-1] == "w" and number > dawn:

            dawn = number+1

        elif res[-1] == "n":

            if number >= dawn and number <= up:

                print("Stan may be honest")
            
            else:

                print("Stan is dishonest")
            
            dawn = 1
            up = 10

        number = int(stdin.readline())

main()