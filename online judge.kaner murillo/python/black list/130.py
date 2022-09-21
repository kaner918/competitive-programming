#https://onlinejudge.org/external/1/130.pdf
#130

from sys import stdin

peoples, start = [int(x) for x in stdin.readline().split()]

while peoples != 0 or start != 0:

    game = [int(x+1) for x in range(peoples)]
    kill = start

    while len(game) > 1:

        i = 0

        counter = 0

        while i < kill:

            if counter > len(game):
                counter = 0
        
            counter+=1
            i+=1
    
        selection = game[counter-2]
        killing = counter-1

        i = 0
        counter = 0
        while i < selection:

            if counter > len(game):
                counter = 0
        
            counter+=1
            i+=1 
        
        game[killing] = game[counter-1]
        game.pop(counter-1)
        kill = game[counter-2]

        print(game)
        
    peoples, start = [int(x) for x in stdin.readline().split()]