#https://onlinejudge.org/external/107/10706.pdf
#10706

from sys import stdin

def form(pre, n, top, ind, val):

    return (pre * (n-top)) + (ind * ((((n**2) + n)/2) - (((top**2) + top)/2) + (val*(top-n))))
def main():

    cases = int(stdin.readline())
    valores = []
    i = 1
    val = 0
    pre = 0
    t = 0
    for j in range(10):
        valores.append(form(pre, (val*10) + 9, t, i, val))
        val = (val*10) + 9
        i+=1
        if(t):
            t *= 11
        else:
            t += 9
    #print(valores)
    for k in range(cases):

        number = int(stdin.readline())        
        i = 1
        val = 0
        pre = 0
        t = 0
        j = 0
        while number > valores[j]:
            pre = form(pre, (val*10) + 9, t, i, val)
            val = (val*10) + 9
            i+=1
            if(t):
                t *= 11
            else:
                t += 9
            j += 1
        print(pre, t, i, val)
        print(form(pre, 10, t, i, val))
        hi = 99999
        low = 1
        while(low + 1 < hi):
            mid = low + ((hi-low)>>1)
            #print(mid, hi, low)
            #print(form(pre, mid, t, i, val))
            #print(number)
            if(number <= (form(pre, mid, t, i, val) if mid > 9 else form(0, mid, 0, 1, 0))):
                hi = mid
            else:
                low = mid
        print(low)
        #print(form(pre, low, t, i, val))
        val = int(number - (form(pre, low, t, i, val) if low > 9 else 45))
        print(val)
        cad = []
        i = 1
        maxi = 1
        cadi = ""
        while(len(cadi) < val):
            #cad.append(str(i))
            cadi += str(i)
            i += 1
        
        print(cadi[val - 1])
    return 0

main()