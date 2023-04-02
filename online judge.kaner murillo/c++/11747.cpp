//https://onlinejudge.org/external/117/11747.pdf
//11747

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int father[1001], range[1001];

void makeSet(int index){

    father[index] = index;
    range[index] = 0;
}

int findSet(int index){ //euristica de comprensión de camino

    if(father[index] == index){

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

    int point1, point2, weight;

    Arista(){}
    Arista(int point1, int point2, int weight){

        this->point1 = point1;
        this->point2 = point2;
        this->weight = weight;
    }

    bool operator<(const Arista&other)const{

        return weight < other.weight;
    }
};

void kruskal(vector<Arista>&aristas, vector<Arista>&nones, int size){

    int i, point1, point2;

    for(i = 0; i<size; i++){

        makeSet(i);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end(); it++){
        
        point1 = it->point1;
        point2 = it->point2;

        if(findSet(point1) != findSet(point2)){

            unionSet(point1, point2);

        }

        else{

            nones.push_back(*it);
        }
    }
}

int main(){

    int points, conections, point1, point2, i, weight;

    while(scanf("%i %i", &points, &conections) && (points || conections)){
        
        vector<Arista>aristas;
        vector<Arista>nones;

        for(i = 0; i<conections; i++){

            scanf("%i %i %i", &point1, &point2, &weight);

            aristas.push_back(Arista(point1, point2, weight));
        }

        kruskal(aristas, nones, points);

        if(nones.size()){

            printf("%i", nones.front().weight);

            for(i = 1; i<nones.size(); i++){

                printf(" %i", nones[i].weight);
            }

            printf("\n");
        }

        else{

            printf("forest\n");
        }
    }

    return 0;
}