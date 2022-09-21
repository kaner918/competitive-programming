
def phs(i, pax):

    if(i, pax) not in mem:

        if i == len(A)-1:

            ans = A[-1]
        
        else:

            ans = float("-inf")

            for k in range(i+1, i+pax):

                ans = max(ans, phs(k, k-i)) + A[i]

            mem[(i,pax)] = ans

    else:

        ans = mem[(i,pax)]
    
    return ans

mem = {}
A = [-1,-1, -1]

ans =  phs(0, len(A)-1)

print(mem)