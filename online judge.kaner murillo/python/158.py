#158
#https://onlinejudge.org/external/1/158.pdf

from sys import stdin
index = 0
star = ["kaner", "*", "**", "***", "****", "*****", "******", "*******"]

def modify(line):

    global index

    list1 = [index]
    index+=1
    string = ""
    i = 2
    flag = False
    counter = 0

    while counter < 3:

        if(ord(line[i]) == 32 and len(string) > 0):


            list1.append(int(string))
            counter+=1
            string = ""

        elif (ord(line[i]) != 32):
            
            string+=line[i]

        i+=1

    while i < len(line):

        if ord(line[i]) != 32:

            flag = True

        if flag:

            string+=line[i]
        i+=1

    list1.append(string)

    return list1

def make_date(range1, date, anio):

    day = date[1]
    mom = date[2]

    for i in range(7):

        day+=1 

        if (mom == 1 or mom == 3 or mom == 5 or mom == 7 or mom == 8 or mom == 10 or mom == 12) and day > 31:

            if mom == 12:
                
                day = 1
                mom = 1

            else:

                day = 1
                mom +=1
        
        elif (mom == 4 or mom == 6 or mom == 9 or mom == 11) and day > 30:

            day = 1
            mom +=1

        elif mom == 2 and anio % 4 == 0 and day > 29:

            day = 1
            mom +=1
        
        elif mom == 2 and anio % 4 != 0 and day > 28:

            day = 1
            mom +=1 

        range1.append([day, mom, i])

def main():

    anio = int(stdin.readline())
    line = stdin.readline().rstrip('\n')
    reminder = []
    dates = []

    while line != "#":
        
        if line[0] == 'A':

            line = modify(line)
            reminder.append(line)

        else:
        
            line = line.split()
            line[1] = int(line[1])
            line[2] = int(line[2])

            dates.append(line)

        line = stdin.readline().rstrip('\n')
    
    for i in range(len(dates)):

        range1 = [[dates[i][1], dates[i][2], 0]]
        remember = []
        make_date(range1, dates[i], anio)
        
        for n in range(len(reminder)):

            for x in range(len(range1)):

                if range1[x][0] == reminder[n][1] and range1[x][1] == reminder[n][2] and x == 0 and reminder[n][-2]-range1[x][2] > 0:
                    
                    aux = list(reminder[n])
                    aux.append(8)
                    remember.append(aux)
                
                elif range1[x][0] == reminder[n][1] and range1[x][1] == reminder[n][2] and x != 0 and reminder[n][-2]-range1[x][2] > 0:

                    aux = list(reminder[n])
                    aux.append(reminder[n][-2]-range1[x][2])
                    remember.append(aux)
        
        if dates[i][2] != 12:

            remember.sort(key= lambda x: (x[2], x[1], -x[-1], x[0]))

        else:

            remember.sort(key= lambda x: (-x[2], x[1], -x[-1], x[0]))

        print("Today is: %2d %2d"%(dates[i][1], (dates[i][2])))

        for n in remember:

            if n[-1] == 8:

                print("%3d %2d *TODAY* %s"%(n[1], n[2], n[4]))
            
            else:

                print("%3d %2d %-7s %s"%(n[1], n[2], star[n[-1]], n[4]))

        if i < len(dates) -1:
            print()
        
main()