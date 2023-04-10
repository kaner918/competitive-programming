//https://onlinejudge.org/external/103/10397.pdf
//10397

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int father[751], range[751];

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

    int index1, index2;
    double weight;

    Arista(){}
    Arista(int index1, int index2, double weight){

        this->index1 = index1;
        this->index2 = index2;
        this->weight = weight;
    }

    bool operator<(const Arista&other)const{

        return weight < other.weight;
    }
    
};

double kruskal(vector<Arista>&aristas){

    double total = 0.0;
    int index1, index2;

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end(); it++){

        index1 = it->index1;
        index2 = it->index2;

        if(findSet(index1) != findSet(index2)){

            unionSet(index1, index2);
            total+=it->weight;
        }
    }

    return total;
}

int main(){

    int size, i, n, x, y, conections, conection1, conection2;

    while(scanf("%i", &size) != EOF){

        vector<pair<int, int>>points;
        vector<Arista>aristas;

        for(i = 0; i<size; i++){

            makeSet(i);
            scanf("%i %i", &x, &y);
            points.push_back(make_pair(x, y));
        }
        
        scanf("%i", &conections);
        
        for(i = 0; i<conections; i++){

            scanf("%i %i", &conection1, &conection2);
            unionSet(conection1-1, conection2-1);
        }

        for(i = 0; i<size; i++){

            for(n = i+1; n<size; n++){

                aristas.push_back(Arista(i, n, sqrt(pow(points[i].first - points[n].first, 2) + pow(points[i].second - points[n].second, 2))));
            }
        }

        printf("%.2lf\n", kruskal(aristas));
    }

    return 0;
}