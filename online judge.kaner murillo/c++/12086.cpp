//https://onlinejudge.org/external/120/12086.pdf
//12086

#include<cstdio>
#include<iostream>

using namespace std;

int A[200001], tree[400002];

void build(int low, int hight, int pos){

    if(low==hight){

        tree[pos] = A[low];
    }

    else{

        int mid = low + ((hight-low)>>1);

        build(low, mid, pos+1);
        build(mid+1, hight, pos+2*(mid-low+1));

        tree[pos] = tree[pos+1] + tree[pos+2*(mid-low+1)];
    }
}

void update(int low, int hight, int pos, int index, int val){

    if(low == hight){

        tree[pos] = val;
    }

    
    else{

        int mid = low + ((hight-low)>>1);

        if(index<=mid){

            update(low, mid, pos+1, index, val);

        }
        
        else{

            update(mid+1, hight, pos+2*(mid-low+1), index, val);

        }
        
        tree[pos] = tree[pos+1] + tree[pos+2*(mid-low+1)];

    }
}

long long int consult(int low, int hight, int L, int H, int pos){

    long long int ans = -1;

    if(low > hight){

        ans = 0;
    }


    else if (low == L && hight == H){

        ans = tree[pos];
    }

    else{

        int mid = L + ((H-L)>>1);

        ans = consult(low, min(mid, hight), L, mid, pos+1) + consult(max(low, mid+1), hight, mid+1, H, pos+2*(mid-L+1));

    }

    return ans;
}


int main(){

    int size, low, hight, val, i, counter = 1;
    string  comand;
    
    while(scanf("%i", &size) && size){
        
        if(counter>1){
            printf("\n");
        }

        printf("Case %i:\n", counter++);

        for(i = 0; i<size; i++){

            scanf("%i", &A[i]);
        }

        build(0, size-1, 0);

        while((cin>>comand) && comand != "END"){

            cin>>low>>hight;

            if(comand == "S"){

                update(0, size-1, 0, low-1, hight);
            }


            else{

                printf("%lld\n", consult(low-1, hight-1, 0, size-1, 0));
            }
        }
    }

    return 0;
}