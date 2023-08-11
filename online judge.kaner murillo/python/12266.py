#https://onlinejudge.org/external/122/12266.pdf
#12266

from sys import stdin
from heapq import heappop, heappush

class Buyer:

    def __init__(self, size, price):

        self.size = size
        self.price = price

    
    def __lt__(self, other):

        return self.price>other.price

class Seller:

    def __init__(self, size, price):

        self.size = size
        self.price = price

    
    def __lt__(self, other):

        return self.price<other.price
    
def main():

    cases = int(stdin.readline())

    for i in range(cases):

        operations = int(stdin.readline())
        trans = -1

        sells = []
        buys = []

        for n in range(operations):

            op = stdin.readline().split()

            if op[0] == "buy":
                heappush(buys, Buyer(int(op[1]), int(op[-1])))

            else:
                heappush(sells, Seller(int(op[1]), int(op[-1])))

            while len(sells) and len(buys) and buys[0].price >= sells[0].price:

                trans = sells[0].price

                if buys[0].size > sells[0].size:

                    buys[0].size-= sells[0].size
                    heappop(sells)

                elif buys[0].size < sells[0].size:

                    sells[0].size-= buys[0].size
                    heappop(buys)

                else:

                    heappop(sells)
                    heappop(buys)
                    

            if not len(sells):  

                print("-", end=" ")
            
            else:
                print(sells[0].price, end=" ")

            if not len(buys):

                print("-", end=" ")
            
            else:
                print(buys[0].price, end=" ")
            
            if trans == -1:
                print("-")
            
            else:
                print(trans)

main()