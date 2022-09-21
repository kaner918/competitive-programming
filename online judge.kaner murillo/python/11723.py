#https://onlinejudge.org/external/117/11723.pdf
#11723

from sys import stdin 

caso = [int(x) for x in stdin.readline().rstrip('\n').split()]
contador = 1

while caso!=[0,0]:

    if (caso[1]*26)+caso[1] >= caso[0]:

        if caso[0]%caso[1] != 0:

            print(f"Case {contador}: {caso[0]//caso[1]}")
        
        else:

            print(f"Case {contador}: {caso[0]//caso[1]-1}")

    else:
        print(f"Case {contador}: impossible")
    
    contador+=1 

    caso = [int(x) for x in stdin.readline().rstrip('\n').split()]