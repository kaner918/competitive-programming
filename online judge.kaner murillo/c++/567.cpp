//https://onlinejudge.org/external/5/567.pdf
//567

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int visits[20];

int bfs(int init, int finish, vector<vector<int>>&graph){

    int position, i;

    queue<int>q;
    q.push(init);
    
    visits[init] = 0;

    while(!q.empty()){

        position = q.front();
        q.pop();

        if(position == finish){

            return visits[position];
        }

        for(i = 0; i<graph[position].size(); i++){

            if(visits[graph[position][i]] == -1){

                visits[graph[position][i]] = visits[position] + 1;
                q.push(graph[position][i]);
            }
        }
    }
}

int main(){

    int vertex, edges, i, n, counter = 1, position = 0, consults, init, finish;
    vector<vector<int>>graph(20);

    while(scanf("%i", &edges) != EOF){
        
        if(position == 0){

            for(i = 0; i<20; i++){

                graph[i].clear();
            }          
        }

        for(i = 0; i<edges; i++){

            scanf("%i", &vertex);

            graph[position].push_back(vertex-1);
            graph[vertex-1].push_back(position); 
            
        }

        if(position == 18){

            printf("Test Set #%i\n", counter);
            scanf("%i", &consults);

            for(n = 0; n<consults; n++){

                scanf("%i %i", &init, &finish);

                for(i = 0; i<20; i++){

                    visits[i] = -1;
                }

                printf("%2i to %2i: %i\n", init, finish, bfs(init-1, finish-1, graph));
            }

            position = -1;
            counter++;
            printf("\n");
        }

        position+=1;
    }


    return 0;   
}