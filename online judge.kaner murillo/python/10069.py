#https://onlinejudge.org/external/100/10069.pdf
#10069

from sys import stdin
import sys

sys.setrecursionlimit(1000000)

def dp(i, j, cad1, cad2, mem):

    ans = None
    key = (i, j)
    if key in mem:
        ans = mem[key]

    else:
        
        if i == len(cad1) or j==len(cad2):
            ans = 0
            if j == len(cad2):
                ans = 1
        
        else:

            ans = dp(i+1, j, cad1, cad2, mem)

            if cad1[i] == cad2[j]:
                ans+=dp(i+1, j+1, cad1, cad2, mem)
            
        mem[key] = ans
    
    return ans

def main():

    cases = int(stdin.readline())

    for i in range(cases):
        
        cad1 = stdin.readline().strip()
        cad2 = stdin.readline().strip()
        mem = {}

        print(dp(0, 0, cad1, cad2, mem))

main()