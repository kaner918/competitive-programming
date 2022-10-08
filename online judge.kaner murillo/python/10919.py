#https://onlinejudge.org/external/109/10919.pdf
#10919

from sys import stdin

prerequisites = stdin.readline().split()

while len(prerequisites) > 1:

    courses = []
    ans = True

    while len(courses) < int(prerequisites[0]):

        courses.extend([int(x) for x in stdin.readline().split()])

    for i in range(int(prerequisites[1])):

        category = [int(x) for x in stdin.readline().split()]
        n = 2
        counter = 0

        if ans == True:

            while n < len(category) and counter < category[1]:

                if category[n] in courses:

                    counter+=1

                n+=1
        
            if counter < category[1]:

                ans = False

    if ans == True:

        print("yes")
    
    else:

        print("no")

    prerequisites  = stdin.readline().split()