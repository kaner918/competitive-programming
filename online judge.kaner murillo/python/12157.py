#https://onlinejudge.org/external/121/12157.pdf
#12157

from sys import stdin 

cases = int(stdin.readline().strip())

for i in range(1,cases+1):

    amount = int(stdin.readline().strip())

    calls = [int(x) for x in stdin.readline().split()]

    mile = 0
    juice = 0

    for n in range(amount):

        mile+=10+(10*(calls[n]//30))
        juice+=15+(15*(calls[n]//60))
    
    if mile<juice:
        print(f"Case {i}: Mile {mile}")
    
    elif mile>juice:
        print(f"Case {i}: Juice {juice}")
    
    else:
        print(f"Case {i}: Mile Juice {mile}")
        


