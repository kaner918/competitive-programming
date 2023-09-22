//https://onlinejudge.org/external/130/13015.pdf
//13015

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

vector<int>fathers(5001);
vector<int>sucers(5001);

int bfs2(int node, vector<int>visits2, vector<vector<int>>&graph){
    
    queue<int>q;
    q.push(node);
    visits2[node] = 0;
    int i, counter = -1;

    while(!q.empty()){
        node = q.front();
        counter++;
        q.pop();

        for(i = 0; i<graph[node].size(); i++){
            if(visits2[graph[node][i]] == -1){
                q.push(graph[node][i]);
                fathers[graph[node][i]]++;
                visits2[graph[node][i]] = visits2[node]+1;
            }
        }
    }

    return counter;
}

int main(){

    int A, B, employees, precedence, employe1, employe2, i, counter, range1, range2, range3, aux, aux2,
    counter2 = 0;

    while(scanf("%i %i %i %i", &A, &B, &employees, &precedence) != EOF){
    
        if(counter2++){
            cin.ignore();
        }
        for(i = 0; i<employees; i++){
            fathers[i] = 0;
            sucers[i] = 0;
        }

        vector<vector<int>>graph(employees);
        vector<int>aux(employees, -1);

        range1 = 0;
        range2 = 0;
        range3 = 0;

        while(precedence--){

            scanf("%i %i", &employe1, &employe2);
            graph[employe1].push_back(employe2);
        }

        for(i = 0; i<employees; i++){
            sucers[i] = bfs2(i, aux, graph);
        }

        for(i = 0; i<employees; i++){
            
            if(fathers[i] >= A && fathers[i] >= B){
                range3++;
            }
            if(sucers[i] >= employees - A){
                range1++;
            }

            if(sucers[i] >= employees - B){
                range2++;
            }
        }

        printf("%i\n%i\n%i\n", range1, range2, range3);
    }

    return 0;
}