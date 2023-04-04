//https://onlinejudge.org/external/101/10147.pdf
//10147

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int father[751], range[751];

void makeSet(int town){

    father[town] = town;
    range[town] = 0; 
}

int findSet(int town){

    if(father[town] == town){
        return town;
    }

    else{

        father[town] = findSet(father[town]);
        return father[town];
    }
}

void unionSet(int town1, int town2){

    town1 = findSet(town1);
    town2 = findSet(town2);

    if(town1 != town2){


        if(range[town1] < range[town2]){

            swap(town1, town2);
        }

        father[town2] = town1;

        if(range[town1] == range[town2]){
            range[town1]++;
        }
    }
}

struct Arista{

    int town1, town2;
    double weight;

    Arista(){}
    Arista(int town1, int town2, double weight){

        this->town1 = town1;
        this->town2 = town2;
        this->weight = weight;
    }

    bool operator <(const Arista&other)const{

        return weight < other.weight;
    }
};

void kruskal(vector<Arista>&aristas, vector<Arista>&mst){

    int town1, town2;

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end(); it++){

        town1 = it->town1;
        town2 = it->town2;

        if(findSet(town1) != findSet(town2)){

            unionSet(town1, town2);
            mst.push_back(*it);
        }
    }
}

int main(){

    int cases, towns, highways, i, n, x, y, town1, town2;
    
    scanf("%i", &cases);

    while(cases--){

        cin.ignore();
        scanf("%i", &towns);
        vector<pair<int, int>>points;
        vector<Arista>aristas;
        vector<Arista>mst;
        
        for(i = 0; i<towns; i++){
            
            scanf("%i %i", &x, &y);

            points.push_back(make_pair(x, y));
            makeSet(i);
        }

        scanf("%i", &highways);

        for(i = 0; i<highways; i++){

            scanf("%i %i", &town1, &town2);
            unionSet(town1-1, town2-1);
        }

        for(i = 0; i<towns; i++){

            for(n = i+1; n<towns; n++){

                if(findSet(i) != findSet(n)){

                    aristas.push_back(Arista(i, n, sqrt(pow(points[i].first - points[n].first, 2) + pow(points[i].second - points[n].second, 2))));
                }
            }
        }

        kruskal(aristas, mst);
    
        if(mst.size()){

            for(i = 0; i<mst.size(); i++){

                printf("%i %i\n", mst[i].town1+1, mst[i].town2+1);
            }
        }

        else{

            printf("No new highways need\n");
        }

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}