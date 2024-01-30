//https://onlinejudge.org/external/114/11402.pdf
//11402

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int>A(1000001);
vector<int>tree(1000001*2);

//1 > buccaneer, 0->other

void build(int pos, int l, int r){

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

void update(int pos, int l, int r, int index){

    if(l == r){
        tree[pos] = (A[l] == 1);
    }

    else{

        int mid = l + ((r-l)>>1);

        if(index<=mid){
            update(pos+1, l, mid, index);
        }
        else{
            update(pos+2*(mid-l+1), mid+1, r, index);
        }

        tree[pos] = tree[pos+1] + tree[pos+2*(mid-l+1)];
    }
}

int querie(int pos, int L, int R, int l, int r){

    if(l>r){
        return 0;
    }
    
    else if(l == L && r == R){
        return tree[pos];
    }

    else{
        int mid = L + ((R-L)>>1);
        return (querie(pos+1, L, mid, l, min(mid, r)) + querie(pos+2*(mid-L+1), mid+1, R, max(l, mid+1), r));
    }
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
                for(k = low; k<hight+1; k++){
                    A[k] = 1;
                    update(0, 0, index-1, k);
                }
            }

            else if(letter == 'E'){
                for(k = low; k<hight+1; k++){
                    A[k] = 0;
                    update(0, 0, index-1, k);
                }
            }

            else if(letter == 'I'){
                for(k = low; k<hight+1; k++){
                    A[k] = !A[k];
                    update(0, 0, index-1, k);
                }
            }

            else{

                printf("Q%i: %i\n", counter++, querie(0, 0, index-1, low, hight));
            }
        }
    }

    return 0;
}