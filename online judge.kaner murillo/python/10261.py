#https://onlinejudge.org/external/102/10261.pdf
#10261

from pprint import pprint
from sys import stdin

def solve(i, n, sum1, sum2, cars, mem):

    ans, key = None, (i, abs(sum1-sum2))

    if key in mem:
        ans = mem[key]
    
    else:

        if i == n:

            ans = [0, [-1]]
        
        else:

            a, b = [0, [-1]], [0, [-1]]

            if sum1 - cars[i] >= 0:
                a = list(solve(i+1, n, sum1-cars[i], sum2, cars, mem))
                a[0]+=1
                a[1] = list(a[1])
                a[1].append(0)

            if sum2 - cars[i] >= 0:
                b = list(solve(i+1, n, sum1, sum2-cars[i], cars, mem))
                b[0]+=1
                b[1] = list(b[1])
                b[1].append(1)

            if a[0] >= b[0]:
                ans = a
            
            else:
                ans = b

        mem[key] = ans
                
    return ans
    
def main():

    cases = int(stdin.readline())
    stdin.readline()

    for i in range(cases):
        
        if i:
            stdin.readline()
            print()

        size = int(stdin.readline())
        cars = []

        size_car = int(stdin.readline())

        while size_car:
            cars.append(size_car/100)
            size_car = int(stdin.readline())
        
        mem = {}
        ans = solve(0, len(cars), size, size, cars, mem)
        print(ans[0])

        for j in range(len(ans[1])-1, 0, -1):
            if not ans[1][j]:
                print("port")
            else:
                print("starboard")    
        

main()