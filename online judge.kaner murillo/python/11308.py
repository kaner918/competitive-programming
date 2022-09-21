#https://onlinejudge.org/external/113/11308.pdf
#11308

from sys import stdin

cases = int(stdin.readline())

for i in range(cases):

    name = stdin.readline().strip()
    binders = [int(x) for x in stdin.readline().split()] #carpetas
    dic = {}
    dic2 = {}
    ans = False

    for n in range(binders[0]):

        ingredients = stdin.readline().split()

        dic[ingredients[0]] = int(ingredients[1])

    for n in range(binders[1]):

        ingredients = stdin.readline().strip()
        dic2[ingredients] = 0
        cIngredients = int(stdin.readline())

        for m in range(cIngredients):

            ingredients2 = stdin.readline().split()

            dic2[ingredients]+= dic[ingredients2[0]]*int(ingredients2[1])

    sort = sorted(dic2.items(), key = lambda x: (x[1], x[0]))   

    print(name.upper())

    for n in sort:

        if n[1] <= binders[-1]:
            print(n[0])
            ans = True
    
    if ans == False:
        print("Too expensive!")

    print()