//https://onlinejudge.org/external/12/1235.pdf
//1235

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<string>

using namespace std;

int distance(int a, int b){

    int dist = 0;

    if(a > b){

        return min(a-b, 9-a+b+1);
    }

    return min(b-a, a+9-b+1);
}

int prim(vector<string>&graph, vector<int>&dist, int size){

    vector<int>visits(size, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    int i, combination, n, weight, auxWeight, coste = 0;

    weight = INT_MAX;
    
    for(i = 1; i<size; i++){

        auxWeight  = 0;

        for(n = 0; n<4; n++){

            auxWeight += distance(graph[0][n] - 48, graph[i][n] - 48);
        }

        if(auxWeight < weight){
            combination = i;
            weight = auxWeight;
        }
    } 

    dist[combination] = weight;
    q.push(make_pair(weight, combination));

    while(!q.empty()){

        weight = q.top().first;
        combination = q.top().second;

        visits[combination] = 1;

        q.pop();

        if(weight == dist[combination]){

            coste+=weight;

            for(i = 1; i<size; i++){

                if(i != combination){

                    auxWeight = 0;

                    for(n = 0; n<4; n++){

                        auxWeight+=distance(graph[combination][n] - 48, graph[i][n] - 48);
                    } 

                    if(!visits[i] && auxWeight < dist[i]){

                        dist[i] = auxWeight;
                        q.push(make_pair(auxWeight, i));
                    }
                }                
            }
        }
    }

    return coste;
}

int main(){

    int cases, i, size;
    string combination;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i", &size);
        vector<string>graph= {"0000"};
        vector<int>dist(size+1, INT_MAX);

        for(i = 0; i<size; i++){

            cin>>combination;
            graph.push_back(combination);    
        }

        printf("%i\n", prim(graph, dist, size+1));
    }

    return 0;
}