#10721
#https://onlinejudge.org/external/107/10721.pdf

from sys import stdin

def dp(sums, n, grupos, contiguos, k, m, mem):

    ans, key = None, (sums, grupos, contiguos)

    if key in mem:
        ans = mem[key]
    
    else:

        if sums >= n:
            ans = ((grupos == k) and (sums == n))

        else:

            a, b = 0, 0
            if contiguos + 1 <= m:
                a = dp(sums, n, grupos, contiguos+1, k, m, mem)
            
            if grupos + 1 <= k:
                b = dp(sums+contiguos, n, grupos+1, 1, k, m, mem)

            ans = a+b

        mem[key] = ans

    return ans  

def main():

    case = [int(x) for x in stdin.readline().split()]

    while case != []:

        mem = {}
        print(dp(0, case[0], 0, 1, case[1], case[2], mem))

        case = [int(x) for x in stdin.readline().split()]

main()