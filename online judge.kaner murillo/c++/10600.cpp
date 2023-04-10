//https://onlinejudge.org/external/106/10600.pdf
//10600

//https://onlinejudge.org/external/104/10462.pdf
//10462

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int father[101], range[101];

void makeSet(int neighbor){

    father[neighbor] = neighbor;
    range[neighbor] = 0;
}

int findSet(int neighbor){

    if(father[neighbor] == neighbor){

        return neighbor;
    }

    else{

        father[neighbor] = findSet(father[neighbor]);
        return father[neighbor];
    }
}

void unionSet(int neighbor1, int neighbor2){

    neighbor1 = findSet(neighbor1);
    neighbor2 = findSet(neighbor2);

    if(neighbor1 != neighbor2){

        if(range[neighbor1] < range[neighbor2]){
            swap(neighbor1, neighbor2);
        }

        father[neighbor2] = neighbor1;

        if(range[neighbor1] == range[neighbor2]){

            range[neighbor1]++;     
        }
    }
}

struct Arista{

    int neighbor1, neighbor2, weight;

    Arista(){}
    Arista(int neighbor1, int neighbor2, int weight){

        this->neighbor1 = neighbor1;
        this->neighbor2 = neighbor2;
        this->weight = weight;
    }

    bool operator<(const Arista&other)const{
        return weight < other.weight;
    }
};

int kruskal(vector<Arista>&aristas, int &sizeMst, vector<Arista>&nonesMst, int size, int prio1, int prio2, int weight){

    int i, neighbor1, neighbor2, total = 0;
    bool flag = true;
    for(i = 0; i<size; i++){

        makeSet(i);
    }

    if(prio1 == -1){

        sort(aristas.begin(), aristas.end());
    }

    else{

        total+=weight;
        unionSet(prio1, prio2);
    }

    for(auto it = aristas.begin(); it!= aristas.end(); it++){

        neighbor1 = it->neighbor1;
        neighbor2 = it->neighbor2;

        if(findSet(neighbor1) != findSet(neighbor2)){

            unionSet(neighbor1, neighbor2);
            total+=it->weight;
            sizeMst++;
        }

        else if(prio1 == -1){

            nonesMst.push_back(*it);
        }
    }

    return total;
}

int main(){

    int cases, sizeMst, neighbors, neighbor1, neighbor2, weight, conections, i, n, total, ans;
    bool flag;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        vector<Arista>aristas;
        vector<Arista>nonesMst;
        flag = true;
        sizeMst = 0;
        scanf("%i %i", &neighbors, &conections);

        while(conections--){

            scanf("%i %i %i", &neighbor1, &neighbor2, &weight);
            aristas.push_back(Arista(neighbor1-1, neighbor2-1, weight));
        }

        total = kruskal(aristas, sizeMst, nonesMst, neighbors, -1, -1, 0);
        ans = INT_MAX;

        printf("%i ", total);
        
        for(n = 0; n<nonesMst.size(); n++){

            vector<Arista>mst2;
            sizeMst = 0;
            total = kruskal(aristas, sizeMst, nonesMst, neighbors, nonesMst[n].neighbor1, nonesMst[n].neighbor2, nonesMst[n].weight);

            if(sizeMst == neighbors-2){
            
                ans = min(ans, total);
                flag = false;
            }
        }

        printf("%i\n", ans);
    }

    return 0;
}
