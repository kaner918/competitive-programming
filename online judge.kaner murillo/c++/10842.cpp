//https://onlinejudge.org/external/108/10842.pdf
//10842

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int father[101], range[101];

void makeSet(int index){

    father[index] = index;
    range[index] = 0;
}

int findSet(int index){

    if(index == father[index]){
        return index;
    }

    else{

        father[index] = findSet(father[index]);
        return father[index];
    }
}

void unionSet(int index1, int index2){

    index1 = findSet(index1);
    index2 = findSet(index2);

    if(index1 != index2){

        if(range[index1] < range[index2]){

            swap(index1, index2);
        }

        father[index2] = index1;

        if(range[index1] == range[index2]){

            range[index1]++;
        }
    }
}

struct Arista{

    int index1, index2, weight;

    Arista(){}
    Arista(int index1, int index2, double weight){

        this->index1 = index1;
        this->index2 = index2;
        this->weight = weight;
    }

    bool operator<(const Arista&other)const{

        return weight > other.weight;
    }
    
};

int kruskal(vector<Arista>&aristas, int points){

    int index1, index2, last, i;

    for(i = 0; i<points; i++){

        makeSet(i);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end(); it++){

        index1 = it->index1;
        index2 = it->index2;

        if(findSet(index1) != findSet(index2)){

            unionSet(index1, index2);
            last = it->weight;
        }
    }

    return last;
}

int main(){

    int cases, i, points, conections, weight, a, b;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i %i", &points, &conections);
        vector<Arista>aristas;

        while(conections--){

            scanf("%i %i %i", &a, &b, &weight);
            aristas.push_back(Arista(a, b, weight));

        }

        printf("Case #%i: %i\n", i, kruskal(aristas, points));    
    }

    return 0;       
}