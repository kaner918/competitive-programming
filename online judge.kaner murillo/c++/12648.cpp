//https://onlinejudge.org/external/126/12648.pdf
//12648

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int>dominators(501);
vector<int>visits(501);
vector<int>years(501);
vector<int>years2(501);
vector<int>vals(501);
vector<int>roots(501);
vector<int>roots2(501);

void dfs(int node, int year, vector<vector<int>>&graph){

    if(!visits[node] || year < dominators[node]){
        visits[node] = 1;

        if(roots[node]){
            dominators[node] = year;
        }

        year = min(years[node], year);

        int i;

        for(i = 0; i<graph[node].size(); i++){
            dfs(graph[node][i], year, graph);
        }
    }
}

int main(){

    int a, b, c, d, i, j, nodes, conections, consults;
    char type;

    while(scanf("%i %i %i", &nodes, &conections, &consults) != EOF){

        vector<vector<int>>graph(nodes);
        
        for(i = 0; i<nodes; i++){
            scanf("%i", &years[i]);
            years2[i] = years[i];
            dominators[i] = INT_MAX;
            visits[i] = 0;
            roots[i] = 0;
            roots2[i] = 0;
            vals[i] = i;
        }

        for(i = 0; i<conections; i++){
            scanf("%i %i", &a, &b);
            a--,b--;
            graph[a].push_back(b);
            roots[b] = 1;
            roots2[b] = 1;
        }

        for(i = 0; i<nodes; i++){
            if(!roots[i]){
                dfs(i, years[i], graph);
            }
        }

        for(i = 0; i<consults; i++){
            cin>>type>>a;
            a--;
            c = -1;
            if(type == 'P'){

                for(j = 0; j<nodes && c == -1; j++){
                    if(vals[j] == a){
                        c = a;
                        d = dominators[j];
                    }
                }

                if(d == INT_MAX){
                    cout<<"*"<<endl;
                }
                else{
                    cout<<d<<endl;
                }
            }

            else{
                cin>>b;
                b--;
                
                for(j = 0; j<nodes; j++){

                    if(vals[j] == a){
                        vals[j] = b;
                    }

                    else if(vals[j] == b){
                        vals[j] = a;
                    }
                }


                for(j = 0; j<nodes; j++){
                    dominators[j] = INT_MAX;
                    visits[j] = 0;
                    years[j] = years2[vals[j]];
                }

                for(j = 0; j<nodes; j++){
                    if(!roots[j]){
                        dfs(j, years[j], graph);
                    }
                }
            }
        }
    }

    return 0;
}