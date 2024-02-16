#https://onlinejudge.org/external/13/1350.pdf
#1350

from sys import stdin

def main():

    cases = int(stdin.readline())
    fibos = [(1, 1), (2, 10)]

    for i in range(cases):

        number = int(stdin.readline())
        flag = False
        
        while fibos[-1][0] <= number:
            flag = True
            fibos.append((fibos[-1][0] + fibos[-2][0], fibos[-1][1] * 10))   
        
        res = 0
        hight = len(fibos) - 1  

        if flag:
            res += fibos[-2][1]
            number -= fibos[-2][0]
            hight-=2
        
        while number > 0:
            low = 0

            while(hight - low > 1 ):
                
                mid = low + ((hight-low)>>1)

                if number > fibos[mid][0]:

                    low = mid;

                elif number < fibos[mid][0]:
                    
                    hight = mid;

                else:

                    low = mid
                    hight = mid + 1

            res+=fibos[low][1]
            number -= fibos[low][0];
        
        print(res)
        
main()