#https://onlinejudge.org/external/124/12455.pdf
#12455

from sys import stdin

def backtracking(numbers:list[int], index:int, combinations:int, list: list[int],  number:int):

    if index  == len(numbers):
        
        if combinations ==  number:
            
            return True
            

        else:

            return False

    else:

        return  backtracking(numbers, index+1, combinations + numbers[index], list,  number) or \
                backtracking(numbers, index+1, combinations, list, number)
        

cases = int(stdin.readline())

for i in range(cases):

    number = int(stdin.readline())
    size = int(stdin.readline())

    numbers = [int(x) for x in stdin.readline().split()]
    list = []

    if backtracking(numbers, 0, 0, list, number):
        print("YES")
    
    else:

        print("NO")