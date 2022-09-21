#https://onlinejudge.org/external/111/11172.pdf
#11172

casos = int(input())

for i in range(casos):

    num1,num2 = [int(x)for x in input().split()]

    if num1<num2:
        print("<")
    
    elif num1>num2:
        print(">")
    
    else:
        print("=")