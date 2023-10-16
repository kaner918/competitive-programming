//https://onlinejudge.org/external/122/12299.pdf
//12299

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<string>

using namespace std;

vector<int>tree(100001*2);
vector<int>A(100001);
vector<int>flags(100001);

void build(int l, int r, int pos){

    if(l == r){
        tree[pos] = A[l];
    }

    else{

        int mid = l + ((r-l)>>1);

        build(l, mid, pos+1);
        build(mid+1, r, pos + 2*(mid-l+1));

        tree[pos] = min(tree[pos+1], tree[pos + 2*(mid-l+1)]);
    }
}

void updte(int l, int r, int pos, int pos_change){

    if(l == r){
        tree[pos] = A[l];
    }

    else{

        int mid = l + ((r-l)>>1);

        if(pos_change<=mid){
            updte(l, mid, pos+1, pos_change);
        }

        else{
            updte(mid+1, r, pos+2*(mid-l+1), pos_change);
        }

        tree[pos] = min(tree[pos+1], tree[pos + 2*(mid-l+1)]);
    }
}

int querie(int L, int R, int l, int r, int pos){

    int ans;

    if(l>r){
        ans = INT_MAX;
    }

    else if(l == L && r == R){
        ans = tree[pos];
    }

    else{

        int mid = L + ((R-L)>>1);

        ans = min(querie(L, mid, l, min(r, mid), pos+1), querie(mid+1, R, max(l, mid+1), r, pos+2*(mid-L+1))) ;
    }

    return ans;
}

int main(){

    int i, j, size, queries, l, r, number, aux;
    char letter;

    while(scanf("%i %i", &size, &queries) != EOF){

        for(i = 0; i<size; i++){
            scanf("%i", &A[i]);
            flags[i] = 1;
        }
        build(0, size-1, 0);
        cin.ignore();
        vector<int>numbers;

        for(i = 0; i<queries; i++){
            scanf("%c", &letter);
            if(letter == 's'){
                vector<int>auxNumbers;
                while(scanf("%c", &letter) && letter != '\n'){ 
                    
                    number = 0;
                    while((letter > 47 && letter < 58)){
                        number*=10;
                        number+= (letter - 48);
                        scanf("%c", &letter);
                    }  
                    
                    if(number){
                        auxNumbers.push_back(--number);
                    }
                }   

                aux = A[auxNumbers[0]];

                for(j = 0; j<auxNumbers.size(); j++){
                    if(j<auxNumbers.size()-1){
                        A[auxNumbers[j]] = A[auxNumbers[j+1]];
                    }
                    if(flags[auxNumbers[j]]){
                        numbers.push_back(auxNumbers[j]);
                        flags[auxNumbers[j]] = 0;
                    }
                }

                A[auxNumbers[auxNumbers.size()-1]] = aux;
            }

            else{
                
                l = -1, r = -1;
                while(scanf("%c", &letter) && letter != '\n'){ 
                    
                    number = 0;
                    while((letter > 47 && letter < 58)){
                        number*=10;
                        number+= (letter - 48);
                        scanf("%c", &letter);
                    }  
    
                    if(l == -1 && number){
                        l = number-1;
                    }

                    else if(number){
                        r = number-1;
                    }
                }   

                for(j = 0; j<numbers.size(); j++){
                    flags[numbers[j]] = 1;
                    updte(0, size-1, 0, numbers[j]);
                }

                printf("%i\n", querie(0, size-1, l, r, 0));
                numbers.clear();
            }
        }
    }

    return 0;
}