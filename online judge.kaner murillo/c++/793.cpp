//https://onlinejudge.org/external/7/793.pdf
//793

#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

void makeSet(int node, vector<int>&father, vector<int>&range){

    father[node] = node;
    range[node] = 0;
}

int findSet(int node, vector<int>&father){

    if(node == father[node]){
        return node;
    }

    father[node] = findSet(father[node], father);
    return father[node];
}

void unionSet(int node1, int node2, vector<int>&father, vector<int>&range){

    node1 = findSet(node1, father);
    node2 = findSet(node2, father);

    if(node1 != node2){

        if(range[node2] > range[node1]){
            swap(node1, node2);
        }

        father[node2] = node1;

        if(range[node1] == range[node2]){
            range[node1]++;
        }
    }
}

int main(){

    int cases, size, i, j, a, b, nones, yes;
    char consult;
    string line;

    scanf("%i", &cases);
    cin.ignore();
    cin.ignore();

    for(i = 0; i<cases; i++){
        
        nones = 0;
        yes = 0;

        scanf("%i", &size);
        cin.ignore();
    
        vector<int>father(size);
        vector<int>range(size);

        for(j = 0; j<size; j++){
            makeSet(j, father, range);
        }

        while(getline(cin, line) && line != ""){

            stringstream stk(line);
            stk>>consult>>a>>b;
            a--;
            b--;

            if(consult == 'c'){
                unionSet(a, b, father, range);
            }            

            else if(findSet(a, father) != findSet(b, father)){
                nones++;
            }

            else{
                yes++;
            }
        }

        printf("%i,%i\n", yes, nones);
        if(i < cases-1){
            printf("\n");
        }
    }
    return 0;
}