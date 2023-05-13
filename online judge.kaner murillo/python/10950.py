#https://onlinejudge.org/external/109/10950.pdf
#10950

from sys import stdin 

counter = 0

def solved(dic, cad, index, res):

    global counter

    if counter < 100:

        if index >= len(cad):

            print(res)
            counter+=1
        
        else:

            if cad[index] == '0' and index + 1 < len(cad):
                solved(dic, cad, index+1, res)
            
            for i in dic:
                if len(i[1]) + index <= len(cad) and cad[index:index+len(i[1])] == i[1]:
                    solved(dic, cad, index+len(i[1]), res+i[0])

def main():
 
    size_dic = int(input())
    global counter
    counter2 = 1

    while size_dic:

        print(f"Case #{counter2}")
        counter2+=1
        dic = []
        counter = 0

        for i in range(size_dic):

            v,c = stdin.readline().split()  
            dic.append((v,c)) 

        cad = stdin.readline().strip()
        dic.sort()
        solved(dic, cad, 0, "")

        size_dic = int(input())
        print()

main()