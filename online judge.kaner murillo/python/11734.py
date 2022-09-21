#https://onlinejudge.org/external/117/11734.pdf
#11734

from sys import stdin

casos = int(stdin.readline())

for i in range(1, casos+1):

    cadenaEstudiantes = stdin.readline().rstrip('\n')
    cadenaJuez = stdin.readline().rstrip('\n')

    aux1 = cadenaEstudiantes.split()

    if cadenaEstudiantes == cadenaJuez:

        print(f"Case {i}: Yes")
    
    elif "".join(aux1) != cadenaJuez:

        print(f"Case {i}: Wrong Answer")

    else:

        print(f"Case {i}: Output Format Error")
    

        
        














        
    

        

        