//https://onlinejudge.org/external/12/1208.pdf
//1208

#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int father[27], range[27];

void makeSet(int node){

    father[node] = node;
    range[node] = 0;
}

int findSet(int node){

    if(node == father[node]){
        return node;
    }

    else{
        father[node] = findSet(father[node]);
        return father[node];
    }
}

void unionSet(int node1, int node2){

    node1 = findSet(node1);
    node2 = findSet(node2);

    if(node1 != node2){

        if(range[node1] < range[node2]){
            swap(node1, node2);
        }

        father[node2] = node1;

        if(range[node1] == range[node2]){
            range[node1]++;
        }
    }
}

struct Arista{

    int city1, city2, coste;

    Arista(){}
    Arista(int city, int cityAux, int coste2){

        this->city1 = city;
        this->city2 = cityAux;
        this->coste = coste2;
    }

    bool operator<(const Arista&other)const{

        if(coste == other.coste){

            if(city1 == other.city1){
                return city2 < other.city2;
            }
            return city1 < other.city1;
        }
        return coste < other.coste;
    }
};

void kruskal(vector<Arista>&aristas, vector<Arista>&mst, int citys){

    int i, city1, city2;

    for(i = 0; i<citys; i++){

        makeSet(i);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end(); it++){

        city1 = it->city1;
        city2 = it->city2;

        if(findSet(city1) != findSet(city2)){

            mst.push_back(*it);
            unionSet(city1, city2);
        }
    }
}

int main(){

    int cases, citys, city, i, n, m, coste, pos;
    string line, aux, number;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        scanf("%i", &citys);
        vector<Arista>aristas;
        vector<Arista>mst;

        cin.ignore();

        for(n = 0; n<citys; n++){

            getline(cin, line);
            stringstream stk(line);
            m = 0;
            while(stk>>aux){

                number = "";
                pos = 0;

                while(pos<aux.length() && aux[pos] != ','){
                    number+=aux[pos];
                    pos++;
                }

                coste = stoi(number);

                if(coste){

                    aristas.push_back(Arista(n, m, coste));
                    //cout<<aristas.back().city1<<" "<<aristas.back().city2<<" "<<aristas.back().coste<<endl;
                }

                m++;
            } 
        }

        kruskal(aristas, mst, citys);

        printf("Case %i:\n", i);

        for(n = 0; n<mst.size(); n++){

            printf("%c-%c %i\n", mst[n].city1+65, mst[n].city2+65, mst[n].coste);
        }
    }

    return 0;
}