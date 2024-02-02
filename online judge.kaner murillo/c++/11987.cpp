//https://onlinejudge.org/external/119/11987.pdf
//11897

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int root[200001], range[100001], sum[100001], sizes[100001];

void makeSet(int x){

    root[x] = x + 100000;
    root[x + 100000] = x + 100000;
    range[x] = 0;
    sum[x] = x+1; 
    sizes[x] = 1;
}

int findSet(int x){

    if(x != root[x]){
        root[x] = findSet(root[x]);
    }

    return root[x];
}

void unionSet(int x, int y){

    int set1, set2;

    set1 = findSet(x);
    set2 = findSet(y);

    if(set1 != set2){

        if(range[set1-100000] < range[set2-100000]){
            swap(set1, set2);
        }

        root[set2] = set1;
        sum[set1-100000]+=sum[set2-100000];
        sizes[set1-100000]+=sizes[set2-100000];

        if(range[set1-100000] == range[set2-100000]){
            range[set1-100000]++;
        }
    }
}

void move(int x, int y){
    
    int set1, set2;

    set1 = findSet(x);
    set2 = findSet(y);

    if(set1 != set2){

        root[x] = set2;
        sum[set1-100000]-=x+1;
        sum[set2-100000]+=x+1;
        sizes[set1-100000]--;
        sizes[set2-100000]++;
    }
}

int main(){

    int size, i, queries, set1, p, q, comandy;

    while(scanf("%i %i", &size, &queries) != EOF){

        for(i = 0; i<size; i++){
            makeSet(i);
        }

        for(i = 0; i<queries; i++){
            scanf("%i %i", &comandy, &p);

            if(comandy != 3){
                scanf("%i", &q);
            }
            p--, q--;

            if(comandy == 1){
                unionSet(p, q);
            }

            else if(comandy == 2){
                move(p, q);
            }

            else{
                set1 = findSet(p);
                printf("%i %i\n", sizes[set1-100000], sum[set1-100000]);
            }
        }
    }

    return 0;
}