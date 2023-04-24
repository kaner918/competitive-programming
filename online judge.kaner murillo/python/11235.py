#https://onlinejudge.org/external/112/11235.pdf
#11235

from sys import stdin

def find(A, tree, l, r, position, val):

    ans = None

    if l == r:

        ans = 0
        
        if A[r] == val:

            ans = 1

    else:

        mid = l + ((r-l)>>1)

        ans = find(A, tree, l, mid, position+1, val) + find(A, tree, mid+1, r, position+2*(mid-l+1), val)
    
    return ans

def build(A, tree, auxTree, l, r, position):


    if l == r:

        tree[position] = (A[r], 1)

    else:

        mid = l + ((r-l)>>1)

        build(A, tree, auxTree, l, mid, position+1)
        build(A, tree, auxTree, mid+1, r, position+2*(mid-l+1))

        if tree[position+1][0] == tree[position+2*(mid-l+1)][0]:

            tree[position] = (tree[position+1][0], tree[position+1][1]+tree[position+2*(mid-l+1)][1])

        else:
            
            if tree[position+1][1] > tree[position+2*(mid-l+1)][1]:

                aux = find(A, auxTree, mid+1, r, position+2*(mid-l+1), tree[position+1][0])
                tree[position] = (tree[position+1][0], tree[position+1][1] + aux)

            elif tree[position+1][1] < tree[position+2*(mid-l+1)][1]:
                
                aux = find(A, auxTree, l, mid, position+1, tree[position+2*(mid-l+1)][0])
                tree[position] = (tree[position+2*(mid-l+1)][0], tree[position+2*(mid-l+1)][1] + aux)

            else:

                aux1 = find(A, auxTree, mid+1, r, position+2*(mid-l+1), tree[position+1][0])
                aux2 = find(A, auxTree, l, mid, position+1, tree[position+2*(mid-l+1)][0])

                if tree[position+2*(mid-l+1)][1] + aux2 > tree[position+1][1] + aux1:

                    tree[position] = (tree[position+2*(mid-l+1)][0], tree[position+2*(mid-l+1)][1] + aux2)                

                else:
                    
                    tree[position] = (tree[position+1][0], tree[position+1][1] + aux1)

def querie(tree, auxTree, L, R, l, r, position):

    ans = None

    if l>r:

        ans = (float("-inf"), float("-inf"))
    
    elif L == l and R == r:

        ans = tree[position]
        print(ans)

    else:

        mid = L+((R-L)>>1)

        ans1 = querie(tree, auxTree, L, mid, l, min(mid, r), position+1)
        ans2 = querie(tree, auxTree, mid+1, R, max(l, mid+1), r, position+2*(mid-L+1))

        print(ans1, ans2)
        
        if ans1[0] == ans2[0]:
            ans = (ans1[0], ans1[1]+ans2[1])

        elif ans1[1] > ans2[1]:
            ans = ans1 
        
        else:

            ans = ans2

    return ans

def main():

    case = [int(x) for x in stdin.readline().split()]

    while len(case) > 1:

        A = [int(x) for x in stdin.readline().split()]
        tree = [0 for _ in range(len(A)*2)]
        auxTree = [0 for _ in range(len(A)*2)]
        build(A, tree, auxTree, 0, case[0]-1, 0)
        
        print(tree)
        print(auxTree)

        for i in range(case[1]):

            querie1 = [int(x) for x in stdin.readline().split()]

            print(querie(tree, auxTree, 0, case[0]-1, querie1[0]-1, querie1[1]-1, 0)[1])
            
        case = [int(x) for x in stdin.readline().split()]

main()