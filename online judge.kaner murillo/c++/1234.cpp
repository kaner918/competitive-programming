//https://onlinejudge.org/external/12/1234.pdf
//1234

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int father[10001], range[10001];

void makeSet(int junction){

    father[junction] = junction;
    range[junction] = 0; 
}

int findSet(int junction){

    if(father[junction] == junction){
        return junction;
    }

    else{

        father[junction] = findSet(father[junction]);
        return father[junction];
    }
}

void unionSet(int junction1, int junction2){

    junction1 = findSet(junction1);
    junction2 = findSet(junction2);

    if(junction1 != junction2){


        if(range[junction1] < range[junction2]){

            swap(junction1, junction2);
        }

        father[junction2] = junction1;

        if(range[junction1] == range[junction2]){
            range[junction1]++;
        }
    }
}

struct Arista{

    int junction1, junction2, weight;

    Arista(){}
    Arista(int junction1, int junction2, int weight){

        this->junction1 = junction1;
        this->junction2 = junction2;
        this->weight = weight;
    }

    bool operator <(const Arista&other)const{

        return weight > other.weight;
    }
};

int kruskal(vector<Arista>&aristas, int size){

    int i, junction1, junction2, cams = 0;

    for(i = 0; i<size; i++){
        makeSet(i);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it != aristas.end(); it++){

        junction1 = it->junction1;
        junction2 = it->junction2;

        if(findSet(junction1) != findSet(junction2)){

            unionSet(junction1, junction2);
        }

        else{

            cams+=it->weight;
        }
    }

    return cams;
}

int main(){

    int cases, junctions, junction1, junction2, roads, weight;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &junctions, &roads);

        vector<Arista>aristas;
        
        while(roads--){

            scanf("%i %i %i", &junction1, &junction2, &weight);
            aristas.push_back(Arista(junction1-1, junction2-1, weight));
        }

        printf("%i\n", kruskal(aristas, junctions));
        
    }

    scanf("%i", &cases);

    return 0;
}