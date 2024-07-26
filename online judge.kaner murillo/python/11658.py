#https://onlinejudge.org/external/116/11658.pdf
#11658

from sys import stdin

def dp(i, n, index, sums, arr, mem):

    ans = None
    key = (i, sums)

    if key in mem:
        ans = mem[key]
    
    else:

        if i == n:

            if(sums<=50.00):
                ans = 100.00
            else:
                ans = sums
        
        else:

            a, b = None, 100.00

            a = dp(i+1, n, index, sums, arr, mem)

            if i != index:
                b = dp(i+1, n, index, sums+arr[i], arr, mem)
            
            ans = min(a, b)
        
        mem[key] = ans
    
    return ans

def main():

    size, index = [int(x) for x in stdin.readline().split()]

    while size or index:
        
        index-=1
        arr = []

        for i in range(size):
            arr.append(float(stdin.readline())) 

        mem = {}

        print("%.2f"%((arr[index]/dp(0, size, index, arr[index], arr, mem)*100.00)))

        size, index = [int(x) for x in stdin.readline().split()]
    
main()|