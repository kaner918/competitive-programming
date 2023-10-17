//https://onlinejudge.org/external/112/11235.pdf
//11235

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int tree[100001*2], frequent[100001];

void build(int l, int r, int pos){

    if(l == r){
        tree[pos] = frequent[l];
    }

    else{
        int left, right, mid = l + ((r-l)>>1);

        build(l, mid, pos+1);
        build(mid+1, r, pos+2*(mid-l+1));
            
        left = tree[pos+1];
        right = tree[pos+2*(mid-l+1)];
        tree[pos] = max(left, right);
    }   
}

int main(){

    int size, queries, l, r, i, j, index, val, preVal, counter;

    while(scanf("%i", &size) && size){
        scanf("%i", &queries);
        counter = 1;
        index = 0;
        for(i = 0; i<size; i++){
            scanf("%i", &val);

            if(i){
                if(val == preVal){
                    counter++;
                }    

                else{
                    for(j = index; j<index+counter; j++){
                        frequent[j] = counter;
                    } 
                    index = index+counter;
                    counter = 1;
                }
            }

            preVal = val;
        }

        for(j = index; j<index+counter; j++){
            frequent[j] = counter;
        } 

        build(0, size-1, 0);
        /* for(i = 0; i<size; i++){
            cout<<frequent[i]<<" "; 
        }
        cout<<endl; */

        for(i = 0; i<size*2; i++){
            cout<<tree[i]<<" "; 
        }
        cout<<endl;

        /* for(i = 0; i<queries; i++){
            scanf("%i %i", &l, &r);
            l--, r--;
            printf("%i\n", querie(0, size-1, l, r, 0));
        } */
    }

    return 0;
}