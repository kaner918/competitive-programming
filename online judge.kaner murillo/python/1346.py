#https://onlinejudge.org/external/13/1346.pdf
#1346

from sys import stdin

def main():

    size = stdin.readline()

    while size != "":

        size = int(size)
        songs = [[] for x in range(size)]
        aux = []
        index = 0

        while len(songs[-1]) != 3:
            aux = [float(x) for x in stdin.readline().split()]
            for i in range(len(aux)):
                songs[index].append(aux[i])
                if len(songs[index]) == 3:
                    index+=1

        index = int(stdin.readline())
        songs.sort(key=lambda x: -(x[2]/x[1]))
        
        print(int(songs[index-1][0]))

        size = stdin.readline()

main()