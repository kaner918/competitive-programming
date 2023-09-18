//https://onlinejudge.org/external/130/13015.pdf
//13015

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

vector<int>roots(5001);
vector<int>visits(5001);
vector<int>fathers(5001);
vector<int>pre(5001);
vector<int>levels(5001);

void bfs(int node, vector<vector<int>>&graph){

    queue<int>q;
    q.push(node);
    visits[node] = 0;
    int i;

    while(!q.empty()){
        node = q.front();
        q.pop();

        for(i = 0; i<graph[node].size(); i++){
            if(visits[graph[node][i]] == -1){
                q.push(graph[node][i]);
                visits[graph[node][i]] = visits[node]+1;
            }

            if(visits[node] > levels[graph[node][i]]){
                fathers[graph[node][i]] = 0;
                levels[graph[node][i]] = visits[node];
            }

            fathers[graph[node][i]]++;
        }
    }
}

void khan(vector<vector<int>>&graph, map<int, int>&test){

    int i, node;
    queue<int>q;
    
    for(i = 0; i<graph.size(); i++){
        if(!roots[i]){
            q.push(i);
            fathers[i] = 1;
        }
    }

    while(!q.empty()){
        
        node = q.front();
        fathers[node]+=pre[node];
        test[fathers[node]]++;
        q.pop();

        for(i = 0; i<graph[node].size(); i++){

            roots[graph[node][i]]--;
            pre[graph[node][i]] = max(pre[graph[node][i]], fathers[node]);

            if(!roots[graph[node][i]]){
                q.push(graph[node][i]);
            }
        }
    }
}

int main(){

    int A, B, employees, precedence, employe1, employe2, i, counter, range1, range2, range3, aux,
    counter2 = 0;

    while(scanf("%i %i %i %i", &A, &B, &employees, &precedence) != EOF){
    
        if(counter++){
            cin.ignore();
        }
        for(i = 0; i<employees; i++){
            roots[i] = 0;
            visits[i] = -1;
            fathers[i] = 0;
            pre[i] = 0;
            levels[i] = 0;
        }

        vector<vector<int>>graph(employees);
        map<int, int>test;
        range1 = 0;
        range2 = 0;
        range3 = 0;

        while(precedence--){

            scanf("%i %i", &employe1, &employe2);

            graph[employe1].push_back(employe2);
            roots[employe2]++; //we change the number of employees, tha are fathers of my current node.
        }

        for(i = 0; i<employees; i++){
            if(visits[i]==-1){
                bfs(i, graph);
            }
        }

        /* cout<<"test"<<endl;
        for(i = 0; i<employees; i++){
            cout<<visits[i]<<" "<<fathers[i]<<endl;
        } */

        khan(graph, test);
        counter = 0;
        for(auto it = test.begin(); it!=test.end() &&  B >= it->first; it++){
            counter+=it->second;
        }

        range3 = employees - counter;
        aux = A;
        counter = 0;

        /* for(auto it = test.begin(); it!=test.end(); it++){
            
            cout<<it->first<<" "<<it->second<<" ";
        }
        cout<<endl; */

        for(auto it = test.begin(); it!=test.end() && aux - it->second >0; it++){
            
            counter+=it->second;
            aux-=it->second;
        }

        range1 = counter;

        aux = B;
        counter = 0;
        for(auto it = test.begin(); it!=test.end() && aux - it->second >=0; it++){
            
            counter+=it->second;
            aux-=it->second;
        }

        range2 = counter;

        printf("%i\n%i\n%i\n", range1, range2, range3);
    }

    return 0;
}