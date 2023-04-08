//https://onlinejudge.org/external/103/10307.pdf
//10307

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

vector<string>graph(52);
int arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1}, father[102], range[102];


void makeSet(int position){

    father[position] = position;
    range[position] = 0;
}

int findSet(int position){

    if(position == father[position]){

        return position;
    }

    else{

        father[position] = findSet(father[position]);
        return father[position];
    }
}

void unionSet(int position1, int position2){

    position1 = findSet(position1);
    position2 = findSet(position2);

    if(position1 != position2){

        if(range[position1] < range[position2]){

            swap(position1, position2);
        }

        father[position2] = position1;

        if(range[position1] == range[position2]){

            range[position1]++;
        }
    }

}

struct Arista{

    int row1, colum1, row2, colum2, dist;

    Arista(){}
    Arista(int row1, int colum1, int row2, int colum2, int dist){

        this->row1 = row1;
        this->colum1 = colum1;
        this->row2 = row2;
        this->colum2 = colum2;
        this->dist = dist;
    }

    bool operator<(const Arista&other)const{

        return dist < other.dist;
    }
};

void bfs(vector<Arista>&aristas, int sizeRow, int sizeColum, int row, int colum){

    /* cout<<"ad: "<<row+1<<" "<<colum+1<<" ads: "<<endl;
 */
    int i, auxRow2, auxColum2, auxRow, auxColum;
    vector<vector<int>>dist(sizeRow, vector<int>(sizeColum, -1));

    queue<pair<int, int>>q;
    q.push(make_pair(row, colum));
    dist[row][colum] = 0;

    while(!q.empty()){

        auxRow = q.front().first;
        auxColum = q.front().second;

        q.pop();

        for(i = 0; i<4; i++){

            auxRow2 = auxRow + arrRow[i];
            auxColum2 = auxColum + arrColum[i];

            if(auxRow2 > -1 && auxColum2 > -1 && auxRow2 < sizeRow && auxColum2 < sizeColum && graph[auxRow2][auxColum2] != '#' && dist[auxRow2][auxColum2] == -1){

                dist[auxRow2][auxColum2] = dist[auxRow][auxColum] + 1;
                q.push(make_pair(auxRow2, auxColum2));
                if(graph[auxRow2][auxColum2] == 'A' || graph[auxRow2][auxColum2] == 'S'){

                    /* cout<<auxRow2+1<<" "<<auxColum2+1<<" coste: "<<dist[auxRow2][auxColum2]<<endl; */

                    aristas.push_back(Arista(row, colum, auxRow2, auxColum2, dist[auxRow2][auxColum2]));
                }
            }
        }
    }

    /* cout<<endl; */
}

int kruskal(vector<Arista>aristas, map<pair<int, int>, int>&indexs){

    int sums = 0;
    pair<int, int>pair1;
    pair<int, int>pair2;

    for(auto it = indexs.begin(); it!=indexs.end(); it++){
        makeSet(it->second);
    }

    sort(aristas.begin(), aristas.end());

    for(auto it = aristas.begin(); it!=aristas.end(); it++){
        
        pair1 = make_pair(it->row1, it->colum1);
        pair2 = make_pair(it->row2, it->colum2);
        
        if(findSet(indexs[pair1]) != findSet(indexs[pair2])){

            unionSet(indexs[pair1], indexs[pair2]);
            sums+=it->dist;
        }
    }

    return sums;
}

int main(){

    int cases, sizeRow, sizeColum, i, n, res, index;
    string line;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i %i", &sizeColum, &sizeRow);
        vector<pair<int, int>>positions;
        vector<Arista>aristas;
        map<pair<int, int>, int>indexs;
        res = 0;
        index = 0;
        cin.ignore();

        for(i = 0; i<sizeRow; i++){
    
            getline(cin, line);
            graph[i] = line;
        
        }

        for(i = 0; i<sizeRow; i++){

            for(n = 0; n<sizeColum; n++){

                if(graph[i][n] != ' ' && graph[i][n] != '#'){
                    positions.push_back(make_pair(i, n));
                    indexs[make_pair(i, n)] = index;
                    index++;
                }
            }
        }

        for(i = 0; i<sizeRow; i++){

            for(n = 0; n<sizeColum; n++){

                if(graph[i][n] == 'A' || graph[i][n] == 'S'){

                    bfs(aristas, sizeRow, sizeColum, i, n);
                }
            }
        }

        printf("%i\n", kruskal(aristas, indexs));

    }


    return 0;
}