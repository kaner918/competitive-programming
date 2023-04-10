//https://onlinejudge.org/external/104/10457.pdf
//10457

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<set>
#include<tuple>
#include<algorithm>

using namespace std;

int father[201], range[201], speed[201], coste[201], maxi[201], mini[201]; 

void makeSet(int junction){

    father[junction] = junction;
    coste[junction] = 0;
    range[junction] = 0;
    speed[junction] = 0;
    maxi[junction] = 0;
    mini[junction] = 0;
}

int findSet(int junction){

    if(junction == father[junction]){

        return junction;
    }

    else{

        father[junction] = findSet(father[junction]);
        return father[junction];
    }
}

void unionSet(int junction1, int junction2, int maxSpeed){

    junction1 = findSet(junction1);
    junction2 = findSet(junction2);
    

    if(junction1 != junction2){

        
        if(mini[junction1] == mini[junction2] && mini[junction1] == 0 && maxi[junction1] == maxi[junction2] && maxi[junction1] == 0){

            mini[junction1] = maxSpeed;
            mini[junction2] = maxSpeed;
            maxi[junction1] = maxSpeed;
            maxi[junction2] = maxSpeed;
            father[junction2] = junction1;
            speed[junction1] = maxSpeed;
            range[junction1]++;
        }

        else{

            if(range[junction1] < range[junction2]){
                swap(junction1, junction2);
            }

            if(maxSpeed < mini[junction1] || maxSpeed > maxi[junction1]){

                coste[junction1] = max(coste[junction1], abs(mini[junction1] - maxSpeed));
                coste[junction1] = max(coste[junction1], abs(maxi[junction1] - maxSpeed));
                coste[junction2] = coste[junction1];
                mini[junction1] = min(maxSpeed, mini[junction1]);
                maxi[junction1] = max(maxSpeed, maxi[junction1]);

                cout<<coste[junction1]<<endl;
            }

            if(range[junction1] == range[junction2]){
                range[junction1]++;
            }
        }
    }
}

struct Arista{

    int junction1, junction2, speed;

    Arista(){}
    Arista(int junction1, int junction2, int speed){

        this->junction1 = junction1;
        this->junction2 = junction2;
        this->speed = speed;
    }

    bool operator<(const Arista&other)const{

        return speed < other.speed;
    }
};

int kruskal(vector<Arista>aristas, int junctions, int init, int finish){

    int i, junction1, junction2, speed, last = 0;

    for(i = 0; i<junctions; i++){

        makeSet(i);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end() && findSet(init) != findSet(finish); it++){

        junction1 = it->junction1;
        junction2 = it->junction2;
        speed = it->speed;

        if(junction1 == init && junction2 == finish){
            return 0;
        }

        else if(findSet(junction1) != findSet(junction2)){

            cout<<"conection "<<junction1<<" "<<junction2<<" "<<speed<<endl;            

            unionSet(junction1, junction2, speed);
            last = junction2;
        }
    }

    return coste[father[finish]];
}

int main(){

    int junctions, conections, i, junction1, junction2, speed, speedInit, speedFinish, queries, init, finish, aux, mini;

    while(scanf("%i %i", &junctions, &conections) != EOF){

        vector<Arista>aristas;

        for(i = 0; i<conections; i++){

            scanf("%i %i %i", &junction1, &junction2, &speed);
            aristas.push_back(Arista(junction1-1, junction2-1, speed));
        }

        scanf("%i %i", &speedInit, &speedFinish);
        scanf("%i", &queries);

        while(queries--){

            scanf("%i %i", &init, &finish);

            /* mini = prim(graph, speedInit, speedFinish, init-1, finish-1); */

            printf("%i\n", speedInit+kruskal(aristas, junctions, init-1, finish-1)+speedFinish);
            
        }
    }


    return 0;
}