//https://onlinejudge.org/external/112/11228.pdf
//11228

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int father[1001], range[1001];

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

    int index, index2, x1, y1, x2, y2;
    double weight;
    bool indication;

    Arista(){}
    Arista(int index, int index2, int x1, int y1, int x2, int y2, double weight, bool indication){

        this->index = index;
        this->index2 = index2;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->weight = weight;
        this->indication = indication;
    }

    bool operator<(const Arista&other)const{
        
        return weight < other.weight;
    }
};

void kruskal(vector<Arista>&aristas, int &states, double &roads, double &railroads, int points){

    int i, index1, index2;

    for(i = 0; i<points; i++){
        makeSet(i);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end(); it++){

        index1 = it->index;
        index2 = it->index2;

        if(findSet(index1) != findSet(index2)){

            if(it->indication){

                roads+=it->weight;
            }

            else{

                railroads+=it->weight;
                states++;
            }

            unionSet(index1, index2);
        }
    }
}

int main(){

    int i, n, m, cases, r, x1, y1, citys, states;
    double roads, railroads, dist;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){
        
        scanf("%i %i", &citys, &r);
        vector<pair<int, int>>points;
        vector<Arista>aristas;
        states = 1; 
        roads = 0.0;
        railroads = 0.0;

        for(n = 0; n<citys; n++){

            scanf("%i %i", &x1, &y1);
            points.push_back(make_pair(x1, y1));
        }

        for(n = 0; n<citys; n++){

            for(m = n + 1; m<citys; m++){
                
                dist = sqrt(pow(points[n].first-points[m].first, 2) + pow(points[n].second-points[m].second, 2));

                aristas.push_back(Arista(n, m, points[n].first, points[n].second, points[m].first, points[m].second, dist, dist<=r));
            }
        }

        kruskal(aristas, states, roads, railroads, citys);

        printf("Case #%i: %i %.0lf %.0lf\n", i, states, round(roads), round(railroads));
    }

    return 0;
}