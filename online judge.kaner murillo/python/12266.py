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
        low_sell = -1
        hight_buy = -1
        trans = -1

        sells = []
        buys = []

        for n in range(operations):

            op = stdin.readline().split()

            if op[0] == "buy":
                heappush(buys, Buyer(int(op[1]), int(op[-1])))

            else:
                heappush(sells, Seller(int(op[1]), int(op[-1])))

            if(len(buys)):
                if hight_buy == -1:
                    hight_buy = buys[0].price

                else:
                    hight_buy = max(buys[0].price)

            if(len(sells)):

                if low_sell == -1:
                    low_sell = sells[0].price

                else:
                    low_sell= max(sells[0].price)

                
            
            if(len(buys) and len(sells)) and buys[0].price >= sells[0].price:

                if(trans == -1):
                    trans = sells[0].price
                
                else:
                    trans = min(trans, sells[0].price)
                
                if buys[0].size > sells[0].size:
                    buys[0].size-=sells[0].size
                    heappop(sells)
                    low_sell = -1
                    
                    if(len(sells)):
                        
                        low_sell = sells[0].price

                elif buys[0].size < sells[0].size:
                    sells[0].size-=buys[0].size
                    heappop(buys)
                    hight_buy = -1
                    
                    if(len(buys)):
                        
                        hight_buy = buys[0].price
                else:
                    
                    heappop(sells)
                    heappop(buys)
                    hight_buy = -1
                    low_sell = -1

                    if(len(sells)):
                        
                        low_sell = sells[0].price
                    
                    if(len(buys)):
                        
                        hight_buy = buys[0].price

            if low_sell == -1:  

                print("-", end=" ")
            
            else:
                print(low_sell, end=" ")

            if hight_buy == -1:

                print("-", end=" ")
            
            else:
                print(hight_buy, end=" ")
            
            if trans == -1:
                print("-")
            
            else:
                print(trans)


main()