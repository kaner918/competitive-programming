#https://onlinejudge.org/external/1/196.pdf
#196

from sys import stdin

matrix = [["" for i in range(18279)] for n in range(1000)]
memo = [[-1 for i in range(18279)] for n in range(1000)] 

def conver(cad, index):

    num = 0
    num2 = 0
    i = index

    while ord(cad[i]) > ord('9'):
        i+=1

    while ord(cad[index]) > ord('9'):
        num+= (ord(cad[index])-64) * 26 ** (i - (index+1))
        index+=1
    
    for i in range(index, len(cad)):
        num2 = num2 * 10 + (ord(cad[i])-48)

    return num-1, num2-1

def dp(row, colum):

    if memo[row][colum] != -1:
        return memo[row][colum]


    else:

        formula = matrix[row][colum].split('+')
        index = 1
        sums = 0
        
        for i in range(len(formula)):

            auxColum, auxRow = conver(formula[i], index)
            sums+=dp(auxRow, auxColum)
            index = 0
            
        memo[row][colum] = sums
        return sums

def main():

    cases = int(stdin.readline())


    for i in range(cases):

        colum, row = [int(x) for x in stdin.readline().split()]

        for n in range(row):
            
            line = stdin.readline().split()

            for m in range(len(line)):

                matrix[n][m] = line[m]
                if matrix[n][m][0] != '=':
                    memo[n][m] = int(matrix[n][m])
                
                else:
                    memo[n][m] = -1

        for n in range(row):

            for m in range(colum-1):

                if(memo[n][m] == -1):
                    dp(n, m)

                print(memo[n][m], end = " ")
            
            if(memo[n][colum-1] == -1):
                dp(n, colum-1)
            
            print(memo[n][colum-1])

main()