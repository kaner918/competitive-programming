#https://onlinejudge.org/external/4/487.pdf
#487

from sys import stdin

res = []
conj = set()

arr_row = [1, 1, 1, 0, -1, -1, -1, 0]
arr_colum = [1, 0, -1, -1, -1, 0, 1, 1]

def solved(row, colum, letters, word):

    global res, arr_row, arr_colum

    if len(word)>2:

        if(word not in conj):
            conj.add(word)
            res.append(word)

    for i in range(8):

        aux_row = row + arr_row[i]
        aux_colum = colum + arr_colum[i]

        if(aux_row > -1 and aux_colum > -1 and aux_row < len(letters) and aux_colum < len(letters) and ord(letters[aux_row][aux_colum]) > ord(word[-1])):

            solved(aux_row, aux_colum, letters, word+letters[aux_row][aux_colum])

def main():

    cases = int(input())
    global conj, res

    for i in range(cases):

        stdin.readline()
        size = int(stdin.readline())
        letters = []
        res = []
        conj = set()

        for n in range(size):

            letters.append(stdin.readline().rstrip('\n'))
        
        for n in range(size):

            for m in range(size):

                solved(n, m, letters, letters[n][m])
        
        res.sort(key=lambda x: (len(x), [ord(c) for c in x]))
            
        for n in range(len(res)):
            print(res[n])

        if i < cases-1:
            print()

main()