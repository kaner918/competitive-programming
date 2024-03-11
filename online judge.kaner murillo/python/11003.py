#https://onlinejudge.org/external/110/11003.pdf
#11003

from sys import stdin

def dp(n, sums, boxes, mem):

    ans, key = None, (n, sums)

    if key in mem:
        ans = mem[key]
    
    else:

        if not n:
            ans = 0
        
        else:

            a, b = None, 0

            a = dp(n-1, sums, boxes, mem)
            
            if sums <= boxes[n-1][1]:
                b = dp(n-1, sums+boxes[n-1][0], boxes, mem) + 1

            ans = max(a, b)
        
        mem[key] = ans
    
    return ans

def main():

    size_boxes = int(stdin.readline())

    while size_boxes:

        boxes = []
        
        for i in range(size_boxes):
            boxes.append([int(x) for x in stdin.readline().split()])
        mem = {}
        print(dp(size_boxes, 0, boxes, mem))
        size_boxes = int(stdin.readline())
main()