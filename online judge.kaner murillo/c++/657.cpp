//https://onlinejudge.org/external/6/657.pdf
//657

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int moveRow[] = {-1, 0, 1, 0}, moveColum[] = {0, 1, 0, -1};

void dfs1(int r, int c, vector<string>&graph, vector<vector<int>>&visits, int component){
    
    int i, newR, newC;
    visits[r][c] = component;
    
    for(i = 0; i<4; i++){
        newR = r + moveRow[i];
        newC = c + moveColum[i];
        if(newR > -1 && newR < graph.size() && newC > -1 && newC < graph[0].size() && graph[newR][newC] != '.' && !visits[newR][newC]){
            dfs1(newR, newC, graph, visits, component);
        }
    }
}

void dfs2(int r, int c, vector<string>&graph, vector<vector<int>>&visits){

    int i, newR, newC;
    visits[r][c] = 1;

    for(i = 0; i<4; i++){
        newR = r + moveRow[i];
        newC = c + moveColum[i];
        if(newR > -1 && newR < graph.size() && newC > -1 && newC < graph[0].size() && graph[newR][newC] == 'X' && !visits[newR][newC]){
            dfs2(newR, newC, graph, visits);
        }
    }
}

int main(){
    
    int w, h, i, j, component, count = 1;

    while(scanf("%i %i", &w, &h) && (w || h)){

        cin.ignore();
        vector<string>graph(h);
        vector<vector<int>>visits(h, vector<int>(w, 0));
        vector<vector<int>>visits2(h, vector<int>(w, 0));
        component = 1;

        for(i = 0; i<h; i++){
            cin>>graph[i];
        }

        for(i = 0; i<h; i++){
            for(j = 0; j<w; j++){
                if(graph[i][j] != '.' && !visits[i][j]){
                    dfs1(i, j, graph, visits, component);
                    component++;
                }
            }
        }

        vector<int>components(component);
        
        for(i = 0; i<h; i++){
            for(j = 0; j<w; j++){
                if(graph[i][j] == 'X' && !visits2[i][j]){
                    dfs2(i, j, graph, visits2);
                    components[visits[i][j]]++;
                }
            }
        }

        sort(components.begin(), components.end());

        printf("Throw %i\n%i", count++, components[1]);

        for(i = 2; i<component; i++){
            printf(" %i", components[i]);
        }
        printf("\n\n");
    }

    return 0;
}
