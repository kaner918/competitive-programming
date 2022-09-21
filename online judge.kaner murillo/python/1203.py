#https://onlinejudge.org/external/12/1203.pdf
#1203

from sys import stdin
from heapq import heappop, heappush

class Items:

    def __init__(self, id, period, acoPeriod): #metodo constructor #self, referencial al objeto mismo.

        self.id = id
        self.period = period
        self.acoPeriod = acoPeriod

    def __repr__(self): #representacion en string del objeto

        return "%d" %(self.id)
    
    def __lt__(self, item): #definir la prioridad

        if self.acoPeriod == item.acoPeriod:
            return self.id < item.id

        return self.acoPeriod < item.acoPeriod

register = stdin.readline().split()
prioQueue = []

while register[0] != "#":

    heappush(prioQueue, Items(int(register[1]), int(register[2]), int(register[2])))

    register  = stdin.readline().split()

task = int(stdin.readline())

for i in range(task):

    print(prioQueue[0])
    aux = heappop(prioQueue)
    aux.acoPeriod += aux.period
    heappush(prioQueue, aux)
    
