#Division of Nlogonia
#https://onlinejudge.org/external/114/11498.pdf

casos = int(input())

while casos!=0:
    
    Mx,My = [int(x) for x in input().split()]

    for i in range(casos):

        x,y = [int(x) for x in input().split()]

        if x<Mx and y>My:
            print("NO")
        
        elif x>Mx and y>My:
            print("NE")
        
        elif x<Mx and y<My:
            print("SO")
        
        elif x>Mx and y<My:
            print("SE")
        
        else:
            print("divisa")
    
    casos = int(input())