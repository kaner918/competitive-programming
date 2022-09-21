#https://onlinejudge.org/external/103/10344.pdf
#10344

from sys import stdin

def operation(numbers:list[int], index:int, result):

    if index == len(numbers):

        if result == 23:

            return True
        
        else:

            return False
    
    else:

        return operation(numbers, index+1, result+numbers[index]) or \
               operation(numbers, index+1, result*numbers[index]) or \
               operation(numbers, index+1, result-numbers[index])
               
numbers = [int(x) for x in stdin.readline().split()]

while numbers != [0,0,0,0,0]:
    
    if operation(numbers,0, numbers[0]):

        print("Possible")
        
    else:

        print("Impossible")

    numbers = [int(x) for x in stdin.readline().split()]