#https://onlinejudge.org/external/100/10082.pdf
#10082

from sys import stdin

keyboard = {'1':'`', '2':'1', '3':'2', '4':'3', '5':'4', '6':'5', '7':'6', '8':'7', '9':'8', '0':'9', '-':'0', '=':'-',
            'w':'Q', 'e': 'W', 'r':'E', 't':'R', 'y':'T', 'u':'Y', 'i': 'U', 'o': 'I', 'p':'O', '[': 'P', ']':'[', '\\':']',
             's':'A', 'd': 'S', 'f': 'D', 'g':'F', 'h': 'G', 'j': 'H', 'k':'J', 'l': 'K', ';': 'L', '\'': ';', 
              'x':'Z', 'c':'X', 'v':'C', 'b': 'V', 'n':'B', 'm':'N', ',':'M', '.': ',', '/': '.',
                ' ': ' '}

def solved(line):

    res = ""

    for i in range(len(line)-1):

        res += keyboard[line[i]]

    return res

def main():

    line = stdin.readline()

    while line != "":

        res = solved(line.lower())
        
        print(res, end="")

        line = stdin.readline()

        if line != "":
            print()

        else:
            print("")
main()