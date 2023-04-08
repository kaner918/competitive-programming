//https://onlinejudge.org/external/10/1013.pdf
//1013

#include<cstdio>
#include<iostream>
#include<vector>
#include<cfloat>
#include<queue>
#include<cmath>

using namespace std;

int father[51];

struct Island{

    int x, y, people;

    Island(){}
    Island(int x, int y, int people){

        this->x = x;
        this->y = y;
        this->people = people;
    }
};

void prim(vector<Island>&islands, vector<double>&dist, int size){

    vector<int>visits(size, 0);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>q;

    int i, island;
    double weight, auxWeight;

    dist[0] = 0.0;
    q.push(make_pair(0.0, 0));

    while(!q.empty()){
        
        weight = q.top().first;
        island = q.top().second;

        q.pop();

        visits[island] = 1;

        if(dist[island] == weight){

            for(i = 0; i<size; i++){

                if(i!=island){

                    auxWeight = sqrt(pow(islands[island].x - islands[i].x, 2) + pow(islands[island].y - islands[i].y, 2));

                    if(!visits[i] && auxWeight < dist[i]){

                        dist[i] = auxWeight;
                        father[i] = island;
                        q.push(make_pair(auxWeight, i));
                    }
                }
            }
        }
    }
}

int main(){

    int size, x, y, people, i, totalPeople, totalPeopleAux, counter = 1, aux;
    double total, higer;

    while(scanf("%i", &size) && size){
        
        vector<Island>islands;
        vector<double>dist(size, DBL_MAX);
        vector<int>flags(size, 0);

        totalPeople = 0;
        total = 0.0;

        for(i = 0; i<size; i++){

            scanf("%i %i %i", &x, &y, &people);
            totalPeople+=people;
            islands.push_back(Island(x, y, people));
            father[i] = -1;
        }

        prim(islands, dist, size);
        
        
        for(i = 0; i<size; i++){

            aux = i;
            higer = dist[i];
            totalPeopleAux = 0;
            if(!flags[aux]){
                totalPeopleAux+=islands[aux].people;
                flags[aux] = 1;
            }

            while(father[aux] != -1){

                higer = max(higer, dist[aux]);
                aux = father[aux];
            }

            total+=totalPeopleAux * higer;
        }

        printf("Island Group: %i Average %.2lf\n\n", counter, total/totalPeople);
        counter++;
    }

    return 0;
}