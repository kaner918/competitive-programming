//https://onlinejudge.org/external/112/11235.pdf
//11235

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int tree[100001*2], frequent[100001], A[100001], start[100001];

void build(int l, int r, int pos){

    if(l == r){
        tree[pos] = frequent[l];
    }

    else{
        int mid = l + ((r-l)>>1);



        build(l, mid, pos+1);
        build(mid+1, r, pos+2*(mid-l+1));
            
        tree[pos] = max(tree[pos+1], tree[pos+2*(mid-l+1)]);
    }   
}

int querie(int L, int R, int l, int r, int pos){

    if(l>r){
        return -1;
    }

    else if(l == L && r == R){
        return tree[pos];
    }

    else{

        int mid = L + ((R-L)>>1);
        return max(querie(L, mid, l, min(mid, r), pos+1), querie(mid+1, R, max(mid+1, l), r, pos+2*(mid-L+1)));
    }
}

int main(){

    int size, queries, l, r, l2, r2, i, j, index, val, preVal, size1, size2, counter;

    while(scanf("%i", &size) && size){
        scanf("%i", &queries);
        counter = 1;
        index = 0;
        for(i = 0; i<size; i++){
            scanf("%i", &val);
            A[i] = val;
            if(i){
                if(val == preVal){
                    counter++;
                }    

                else{
                    for(j = index; j<index+counter; j++){
                        frequent[j] = counter;
                        start[j] = index;
                    } 
                    index = index+counter;
                    counter = 1;
                }
            }

            preVal = val;
        }

        for(j = index; j<index+counter; j++){
            frequent[j] = counter;
            start[j] = index;
        } 

        build(0, size-1, 0);

        for(i = 0; i<queries; i++){
            scanf("%i %i", &l, &r);
            l--, r--;

            if(A[l] == A[r]){
                printf("%i\n", r-l+1);
            }
            else{

                size1 = frequent[l] - (l - start[l]);
                size2 = r - start[r] + 1;

                if(size1 + size2 == r-l+1){
                    printf("%i\n", max(size1, size2));
                }

                else{
                    printf("%i\n", max(max(size1, size2), querie(0, size-1, l+size1, r-size2, 0)));
                }

            }
        }
    }

    return 0;
}