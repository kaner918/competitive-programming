#https://onlinejudge.org/external/104/10487.pdf
#10487

from sys import stdin

sizeNumbers = int(stdin.readline())
counter = 1

while sizeNumbers != 0:


    numbers = []

    for i in range(sizeNumbers):

        numbers.append(int(stdin.readline()))
    
    consults = int(stdin.readline())

    print(f"Case {counter}:")

    for i in range(consults):

        number = int(stdin.readline())
        sum = 0
        distance = 1001
        n = 0

        while n < len(numbers) and distance!=0:

            m = n+1

            while m < len(numbers) and distance != 0:

                if abs(number - (numbers[n] + numbers[m])) < distance:

                    sum = numbers[n] + numbers[m]
                    distance =abs(number - (numbers[n] + numbers[m]))

                m+=1

            n+=1
        
        print(f"Closest sum to {number} is {sum}.")

    sizeNumbers = int(stdin.readline())

    counter+=1