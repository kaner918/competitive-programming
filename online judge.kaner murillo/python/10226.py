#https://onlinejudge.org/external/102/10226.pdf
#10226

from sys import stdin

def main():

    cases = int(stdin.readline())
    stdin.readline()

    for i in range(cases):

        dic = {}
        line = stdin.readline().strip()
        counter = 0

        while line != "":

            if line in dic:

                dic[line]+=1
            
            else:

                dic[line]=1
            
            counter+=1

            line  = stdin.readline().strip()

        list_names = sorted(dic.keys())

        for n in list_names:

            print("%s %.4f"%(n, (dic[n]/counter*100)))
        
        if i<cases-1:
            print()

main()