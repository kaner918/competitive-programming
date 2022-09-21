#https://onlinejudge.org/external/107/10776.pdf
#10776

from sys import stdin

def combination(cad: list[str], index:int, combinations: list[str], size:int, set1:set):

    if index==len(cad):

        if len(combinations) == size:

            set1.add("".join(combinations)) 
    
    else:
        
        aux = list(combinations)
        aux.extend(cad[index])    

        combination(cad, index+1, aux, size, set1)
        combination(cad, index+1, combinations, size, set1)


def main():

    cad = stdin.readline().split()

    while cad != []:
        
        cad[0] = list(cad[0])
        cad[0].sort()
        set1 = set()

        combination(cad[0], 0, [], int(cad[1]), set1)

        sort = sorted(list(set1))

        for i in sort:
            print(i)

        cad = stdin.readline().split()   

main()