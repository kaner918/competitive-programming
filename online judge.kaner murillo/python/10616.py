#https://onlinejudge.org/external/106/10616.pdf
#10616

from sys import stdin

def dp(i, n, counter, sums, d, numbers, mem):

    ans, key = None, (i, counter, sums)

    if key in mem:
        ans = mem[key]
    
    else:

        if i == n:
            ans = (not sums and not counter)

        else:

            ans = dp(i+1, n, counter, sums%d, d, numbers, mem)
            
            if counter:
                ans+=dp(i+1, n, counter-1, (sums+numbers[i])%d, d, numbers, mem)

        mem[key] = ans
    
    return ans

def main():

    size_numbers, queries = [int(x) for x in stdin.readline().split()]
    counter = 1

    while size_numbers:
        
        numbers = []
        print(f"SET {counter}:")

        for i in range(size_numbers):
            numbers.append(int(stdin.readline()))

        for i in range(1, queries+1):
            d, m = [int(x) for x in stdin.readline().split()]
            mem = {}
            print(f"QUERY {i}: {dp(0, size_numbers, m, 0, d, numbers, mem)}")

        counter+=1
        size_numbers, queries = [int(x) for x in stdin.readline().split()]

main()