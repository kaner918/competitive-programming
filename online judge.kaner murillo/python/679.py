#https://onlinejudge.org/external/6/679.pdf
#679

from sys import stdin


def main():

    cases = int(stdin.readline())

    while cases != -1:


        for i in range(cases):

            depth, label = [int(x) for x in stdin.readline().split()]
            flags = [False for x in range(524288)]

            for n in range(label):

                level = 1
                act = 1
                pre = None

                while level != depth:

                    pre = act

                    if not flags[act]:

                        act = act*2

                    else:

                        act = act*2+1 

                    flags[pre] = not flags[pre]
                    level+=1

            print(act)

        cases = int(stdin.readline())
main()