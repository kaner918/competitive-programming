//https://onlinejudge.org/external/117/11733.pdf
//11733

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int father[10001], range[10001];

void makeSet(int index){

    father[index] = index;
    range[index] = 0;
}

int findSet(int index){

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

    int location1, location2, weight;

    Arista(){}
    Arista(int location1, int location2, int weight){

        this->location1 = location1;
        this->location2 = location2;
        this->weight = weight;
    }

    bool operator<(const Arista&other)const{

        return weight < other.weight;
    }

};

void kruskal(vector<Arista>&aristas, vector<Arista>&res, int &airs, int&coste, int airCoste){

    int i, index1, index2;

    for(i = 0; i<airs; i++){
        makeSet(i);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it != aristas.end(); it++){

        index1 = it->location1;
        index2 = it->location2;

        if(findSet(index1) != findSet(index2)){

            unionSet(index1, index2);

            coste+=it->weight;
            res.push_back(*it);
            airs--;
        }
    }
}

int main(){
    
    int cases, i, n, coste, locations, newLocations, conections, airCoste, location1, location2, weight;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i %i %i", &locations, &conections, &airCoste);

        vector<Arista>aristas;
        vector<Arista>res;

        coste = 0;
        newLocations = 0;

        while(conections--){

            scanf("%i %i %i", &location1, &location2, &weight);
            aristas.push_back(Arista(location1-1, location2-1, weight));
        }

        kruskal(aristas, res, locations, coste, airCoste);

        n = res.size()-1;

        while(n > -1 && res[n].weight >= airCoste){

            coste-=res[n].weight;
            newLocations++;
            n--;
        }

        printf("Case #%i: %i %i\n", i, coste + (newLocations + locations) * airCoste, newLocations + locations);
    }

    return 0;
}