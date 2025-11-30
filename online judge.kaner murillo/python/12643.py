#https://onlinejudge.org/external/126/12643.pdf
#12643

from sys import stdin

def main():

        tournament = [int(x) for x in stdin.readline().split()]

        while tournament != []:
        
                n = tournament[0]
                p1 = min(tournament[1], tournament[2])
                p2 = max(tournament[1], tournament[2])
                l = 1
                h = 2 ** n
                flag = False 

                while not flag:
                        mid = l + ((h-l)>>1)
                        if p1 <= mid and p2 > mid:
                                flag = True
                        elif p1 <= mid:
                                h = mid
                                n-=1
                        else:
                                l = mid + 1
                                n-=1

                print(n)

                tournament = [int(x) for x in stdin.readline().split()]

if __name__ == "__main__":
        main()