//https://onlinejudge.org/external/125/12532.pdf
//12532

#include<cstdio>
#include<iostream>

using namespace std;

int A[100001], tree[200002];

void build(int low, int hight, int pos){

    if(low==hight){

        tree[pos] = A[low];
    }

    else{

        int mid = low + ((hight-low)>>1);

        build(low, mid, pos+1);
        build(mid+1, hight, pos+2*(mid-low+1));

        tree[pos] = tree[pos+1] * tree[pos+2*(mid-low+1)];
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
        
        tree[pos] = tree[pos+1] * tree[pos+2*(mid-low+1)];

    }
}

int consult(int low, int hight, int L, int H, int pos){

    long long int ans = -1;

    if(low > hight){

        ans = 1;
    }


    else if (low == L && hight == H){

        ans = tree[pos];
    }

    else{

        int mid = L + ((H-L)>>1);

        ans = consult(low, min(mid, hight), L, mid, pos+1) * consult(max(low, mid+1), hight, mid+1, H, pos+2*(mid-L+1));

    }

    return ans;
}


int main(){

    int size, low, querys, hight,i, val;
    string  comand, res;
    
    while(scanf("%i %i", &size, &querys) != EOF){

        res = "";

        for(i = 0; i<size; i++){

            scanf("%i", &A[i]);

            if(A[i]<0){
                A[i] = -1;
            }
            else if(A[i] > 0){
                A[i] = 1;
            }
        }

        build(0, size-1, 0);
        i = 0;

        while(i<querys){

            cin>>comand>>low>>hight;

            if(comand == "C"){

                if(hight<0){
                    hight = -1;
                }
                else if(hight > 0){
                    hight = 1;
                }
                
                update(0, size-1, 0, low-1, hight);
            }


            else{

                val = consult(low-1, hight-1, 0, size-1, 0);

                if(val<0){
                    res+='-';
                }
                else if(val > 0){
                    res+='+';
                }
                else{

                    res+='0';
                }
            }

            i++;
        }

        cout<<res<<endl;
    }

    return 0;
}