#https://onlinejudge.org/external/120/12086.pdf
#12086

from sys import stdin

def build(A, tree, low, hight, pos):

    if low == hight:

        tree[pos] = A[low]
    
    else:

        mid = low + ((hight-low)>>1)

        build(A, tree, low, mid, pos+1)
        build(A, tree, mid+1, hight, pos+2*(mid-low+1))

        tree[pos] = tree[pos+1] + tree[pos+2*(mid-low+1)]

def update(tree, low, hight, pos, index, val):

    if low == hight:

        tree[pos] = val
    
    else:

        mid = low + ((hight-low)>>1)

        if(index<=mid):
            update(tree, low, mid, pos+1, index, val)
        
        else:
            update(tree, mid+1, hight, pos+2*(mid-low+1), index, val)
        
        tree[pos] = tree[pos+1] + tree[pos+2*(mid-low+1)]

def consult(tree, low, hight, L, H, pos):

    ans = None
    
    if low > hight:

        ans = 0

    elif low == L and hight == H: 

        ans = tree[pos]
    
    else:

        mid = L + ((H-L)>>1)

        ans = consult(tree, low, min(mid, hight), L, mid, pos+1) + consult(tree, max(low, mid+1), hight, mid+1, H, pos+2*(mid-low+1))

    return ans

def main():


    size = int(stdin.readline())
    counter = 1

    while size:

        print(f"Case {counter}:")
        counter+=1

        A = [0 for _ in range(size)]
        tree = [0 for _ in range(size*2)]

        for i in range(size):

            A[i] = int(stdin.readline())


        build(A, tree, 0, size-1, 0)

        comand = stdin.readline().split()

        while len(comand) > 2:

            if comand[0] == 'S':

                update(tree, 0, size-1, 0, int(comand[1])-1, int(comand[2]))

            else:

                print(consult(tree, int(comand[1])-1, int(comand[2])-1, 0, size-1, 0))

            comand = stdin.readline().split()

        size = int(stdin.readline())

        if size:
            print()

if __name__ == "__main__":
    main()