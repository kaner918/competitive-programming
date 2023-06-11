#https://onlinejudge.org/external/123/12324.pdf
#12324

from sys import stdin

travels = [0 for _ in range(100)]
feces = [0 for _ in range(100)]
memo = []

def dp(index, size, fece):

    if index == size:
        return 0
    
    elif memo[index][fece] != -1:

        return memo[index][fece]

    else:

        a = 0
        b = float('inf')
        new_fece = fece+feces[index]

        if new_fece > size:
            new_fece = size

        a = travels[index] + dp(index+1, size, new_fece)
        
        if fece:

            b = (travels[index] // 2) + dp(index+1, size, new_fece-1)
        
        memo[index][fece] = min(a, b)
        return memo[index][fece]
    
def main():

    size = int(stdin.readline())
    global memo

    while size:

        memo = [[-1 for _ in range(size+1)] for _ in range(size)]

        for i in range(size):

            travels[i], feces[i] = [int(x) for x in stdin.readline().split()]

        print(travels[0] + dp(1, size, feces[0]))

        size = int(stdin.readline())
main()