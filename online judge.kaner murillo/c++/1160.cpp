//https://onlinejudge.org/external/11/1160.pdf
//1160

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

int father[100001], range[100001];

void makeSet(int compound){

    father[compound] = compound;
    range[compound] = 0; 
}

int findSet(int compound){

    if(father[compound] == compound){
        return compound;
    }

    else{

        father[compound] = findSet(father[compound]);
        return father[compound];
    }
}

void unionSet(int compound1, int compound2){

    compound1 = findSet(compound1);
    compound2 = findSet(compound2);

    if(compound1 != compound2){


        if(range[compound1] < range[compound2]){

            swap(compound1, compound2);
        }

        father[compound2] = compound1;

        if(range[compound1] == range[compound2]){
            range[compound1]++;
        }
    }
}

struct Arista{

    int compound1, compound2;

    Arista(){}
    Arista(int compound1, int compound2){

        this->compound1 = compound1;
        this->compound2 = compound2;
    }
};

int kruskal(vector<Arista>&aristas, set<int>&numbers){

    int i, ignores = 0, compound1, compound2;

    for(auto it = numbers.begin(); it!=numbers.end(); it++){
        makeSet(*it);
    }

    for(auto it = aristas.begin(); it!=aristas.end(); it++){

        compound1 = it->compound1;
        compound2 = it->compound2;

        if(findSet(compound1) != findSet(compound2)){

            unionSet(compound1, compound2);
        }

        else{

            ignores++;
        }
    }

    return ignores;
}

int main(){

    int compound1, compound2;
    string separate;
    bool flag = true;

    while(flag){

        vector<Arista>aristas;
        set<int>numbers;

        while(scanf("%i", &compound1) && compound1 != -1){
            
            scanf("%i", &compound2);
            aristas.push_back(Arista(compound1-1, compound2-1));
            numbers.insert(compound1-1);
            numbers.insert(compound2-1);
        }
        
        printf("%i\n", kruskal(aristas, numbers));

        cin.ignore();
        if(!getline(cin, separate)){
            flag = false;
        }
    }

    return 0;
}