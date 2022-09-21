#https://onlinejudge.org/external/123/12372.pdf
#12372

casos = int(input())

for i in range(1,casos+1):
    
    num1,num2,num3 = [int(x)for x in input().split()]

    if num1<=20 and num2<=20 and num3<=20:
        print(f"Case {i}: good")
    
    else:
        print(f"Case {i}: bad")