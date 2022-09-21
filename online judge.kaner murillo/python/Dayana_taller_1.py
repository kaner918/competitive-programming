###punto1

def isPrime(number):

    for i in range(2, number):

        if number % i == 0:

            return False
    
    return True

###punto2

def drawDiagonal(number):

    for i in range(number):

        for n in range(i):

            print(".", end="")
        
        print("\\")

###punto3

def primeList(number):

    lista = []

    for i in range(3, number):

        if isPrime(i):

            lista.append(i)
    
    return lista

###punto4

def foodMachine(input_money):

    if input_money < 0:

        return -1

    a,b,c,d = 0,0,0,0

    d = input_money//1000
    input_money -= (1000*(input_money //1000))
    

    c = input_money//500
    input_money -= (500*(input_money //500))

    b = input_money//200
    input_money -= (200*(input_money //200))

    a = input_money//100
    input_money -= (200*(input_money //200))

    return [a,b,c,d]
