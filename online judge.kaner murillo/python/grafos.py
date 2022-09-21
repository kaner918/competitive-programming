#grafos-practica.
from collections import deque
import numpy as np
#import matplotlib.pyplot as plt

vec = [0 for x in range(4)]

def dfs(v):

    vec[v] = 1
    print(v)

    for u in grafo[v]:

        if vec[u] == 0:

            dfs(u)

def bfs(v):

    queue = deque()
    vec[v] = 1
    queue.append(v)

    while len(queue) > 0:

        v = queue.popleft()
        print(v)
        
        for u in grafo[v]:

            if vec[u] == 0:

                vec[u] = 1
                queue.append(u)
                
grafo = [ 

    [1,2], #0
    [0,3], #1
    [], #2
    [0], #3
    [2], #4
]

#bfs(0)

''' 
implementación en c++

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int dfs(int v, vector<vector<int>>&grafo, vector<bool>&visit){
    
    visit[v] = true;
    printf("%i\n", v);
    
    for(int u = 0; u<grafo[v].size(); u++){
        
        if(visit[grafo[v][u]] == false){
            
            dfs(grafo[v][u], grafo, visit);
        }
    }
    
    return 0;
}

int bfs(int v, vector<vector<int>>&grafo, vector<bool>&visit){
    
    queue<int>cola;
    visit[v] = true;
    cola.push(v);
    
    while(!cola.empty()){
        
        v = cola.front();
        printf("%i\n", v);
        cola.pop();
        
        for(int u = 0; u<grafo[v].size(); u++){
            
            if(visit[grafo[v][u]] == false){
                
                visit[grafo[v][u]] = true;
                cola.push(grafo[v][u]);
            }
        }
    }
    
    return 0;
}

int main()
{
    vector<vector<int>>grafo = {{4,5,1}, {0,2,3,4},{1,5},{1},{0,1},{0,2},{}};
    vector<bool>visit = {false,false,false,false,false,false};
    
    bfs(0, grafo, visit);

    return 0;
}

'''
matriz1 = [[],[]]
matriz2 = [[],[]]

for i in range(200):
    
    matriz1[0].append(i)
    matriz2[0].append(i)
    
    matriz1[1].append(1.01 ** i)
    matriz2[1].append(0.99 ** i )

print(matriz1)
print(matriz2)