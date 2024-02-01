//https://onlinejudge.org/external/114/11402.pdf
//11402

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int>A(1000001);
vector<int>tree(1000001*2);
vector<int>marked(1000001*2);

//1 > buccaneer, 0->other

void build(int pos, int l, int r){

    marked[pos] = -1;

    if(l == r){
        tree[pos] = (A[l] == 1);
    }

    else{

        int mid = l + ((r-l)>>1);

        build(pos+1, l, mid);
        build(pos+2 * (mid-l+1), mid+1, r);
        tree[pos] = tree[pos+1] + tree[pos+2*(mid-l+1)];
    }
}

void push(int pos, int mid, int l, int flag){
    if(marked[pos] != -1){
        if(flag){
            marked[pos+1] = marked[pos];
            marked[pos+2*(mid-l+1)] = marked[pos];
        }
        marked[pos] = -1;
    }
}

void update(int pos, int L, int R, int l, int r, int val, int flag){

    int mid = L + ((R-L)>>1), res;

    if(marked[pos] != -1 && marked[pos] != -2){
        tree[pos] = (R-L+1) * marked[pos];
        push(pos, mid, L, L!=R);
    }

    else if(marked[pos] == -2){
        res = tree[pos];
        tree[pos] = (R-L+1)-res;
        push(pos, mid, L, L!=R);
    }

    if(l<=r){

        if(L == l && R == r){
            
            if(flag){
                res = tree[pos];
                tree[pos] = (R-L+1)-res;
                cout<<L<<" "<<R<<" "<<tree[pos]<<endl;

                if(L != R){
                    marked[pos+1] = -2;
                    marked[pos+2*(mid-L+1)] = -2;
                }
            }


            else{

                tree[pos] = (R-L+1) * val;
                if(L != R){
                    marked[pos+1] = val;
                    marked[pos+2*(mid-L+1)] = val;
                }
            }
        }

        else{
            update(pos+1, L, mid, l, min(mid, r), val, flag);
            update(pos+2*(mid-L+1), mid+1, R, max(mid+1, l), r, val, flag);
            tree[pos] = tree[pos+1] + tree[pos+2*(mid-L+1)];
        }
    }
}

int querie(int pos, int L, int R, int l, int r){

    int ans,  mid = L + ((R-L)>>1), res;

    if(marked[pos] != -1 && marked[pos] != -2){
        tree[pos] = (R-L+1) * marked[pos];
        push(pos, mid, L, L!=R);
    }

    else if(marked[pos] == -2){
        res = tree[pos];
        cout<<L<<" "<<R<<" hi: "<<res<<" after: ";
        if(!res){
            tree[pos] = (R-L+1);
        }
        else{
            tree[pos] = (R-L+1)-res;
        }
        cout<<tree[pos]<<endl;
        push(pos, mid, L, L!=R);
    }

    if(l>r){
        ans = 0;
    }
    
    else if(L == l && R == r){
        return tree[pos];
    }

    else{
        ans = (querie(pos+1, L, mid, l, min(mid, r)) + querie(pos+2*(mid-L+1), mid+1, R, max(l, mid+1), r));
    }

    return ans;
}

int main(){

    int cases, counter, size, size2, i, j, k, l, low, hight, index, q;
    char consult;
    string cad;
    char letter;

    scanf("%i", &cases);

    for(i = 0; i<cases; i++){

        printf("Case %i:\n", i+1);
        index = 0;
        counter = 1;
        scanf("%i", &size);

        for(j = 0; j<size; j++){
            scanf("%i", &size2);
            cin.ignore();
            getline(cin, cad);
            for(k = 0; k<size2; k++){
                for(l = 0; l<cad.length(); l++){
                    A[index++] = cad[l] - 48;
                }
            }
        }

        build(0, 0, index-1);

        scanf("%i", &q);

        for(j = 0; j<q; j++){
            cin.ignore();
            scanf("%c %i %i", &letter, &low, &hight);

            if(letter == 'F'){
            
                update(0, 0, index-1, low, hight, 1, 0);
            }

            else if(letter == 'E'){
                update(0, 0, index-1, low, hight, 0, 0);
            }

            else if(letter == 'I'){
                update(0, 0, index-1, low, hight, 0, 1);
            }

            else{

                printf("Q%i: %i\n", counter++, querie(0, 0, index-1, low, hight));
            }
        }
    }

    return 0;
}