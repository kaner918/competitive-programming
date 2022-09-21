#https://onlinejudge.org/external/128/12896.pdf
#12896

from sys import stdin

cases = int(stdin.readline())
dic = {1:[".", ",", "?", '"'], 2:"abc", 3:"def", 4:"ghi", 5:"jkl", 6:"mno", 7:"pqrs", 8:"tuv", 9:"wxyz", 0:" "}
for i in range(cases):

    size = int(stdin.readline())

    numbers = [int(x) for x in stdin.readline().split()]
    counts = [int(x) for x in stdin.readline().split()]

    cad = []

    for n in range(size):

        cad.append(dic[numbers[n]][counts[n]-1])
    
    print("".join(cad))
    