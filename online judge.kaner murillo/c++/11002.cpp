//https://onlinejudge.org/external/110/11002.pdf
//11002

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
#include<tuple>

using namespace std;

int sizeRow, sizeColum1, sizeColum2;
vector<vector<int>>graph(100, vector<int>(100));
vector<vector<int>>memo(100, vector<int>(100));

int arrColum[] = {1, -1};

int bfs(){

    int node, coste, mini = INT_MAX, i, row, colum, auxColum;

    queue<tuple<int, int, int>>q;
    set<tuple<int, int, int>>conj;
    tuple<int, int, int>aux;

    q.push(make_tuple(graph[99][50], 99, 50));
    q.push(make_tuple(-graph[99][50], 99, 50));
    
    while(!q.empty() && mini){

        coste = get<0>(q.front());
        row = get<1>(q.front());
        colum = get<2>(q.front());

        cout<<row<<" "<<colum<<" "<<coste<<endl;

        q.pop();

        if(row == sizeRow){
            mini = (mini, abs(coste));
        }

        else{
            
            for(i = 0; i<2; i++){
                
                auxColum = colum + arrColum[i];
                /* cout<<auxColum<<" "<<sizeColum1<<" "<<sizeColum2<<endl; */
                if(auxColum > sizeColum1 && auxColum < sizeColum2){
                    /* cout<<"hi"<<endl; */
                    aux = make_tuple(coste + graph[row][auxColum], row-1, auxColum);
                    if(conj.find(aux) == conj.end()){
                        q.push(aux);
                        conj.insert(aux);
                    }

                    aux = make_tuple(coste - graph[row][auxColum], row-1, auxColum);
                    if(conj.find(aux) == conj.end()){
                        q.push(aux);
                        conj.insert(aux);
                    }
                }
            }

        }
    }

    return mini;
}

int main(){

    int ans, size, number, i, j, counter, counter2, colum, row, sum, sum2, auxColum;

    while(scanf("%i", &size) && size){

        counter = size;
        counter2 = 1;
        sum = 1;
        sum2 = -1;
        colum = 50;
        row = 99;
        for(i = 0; i<size*2; i++){
            auxColum = colum;
            for(j = 0; j<counter2; j++){
                scanf("%i", &number);
                graph[row][auxColum] = number;
                memo[row][auxColum] = -1;
                auxColum+=2;
            }   

            if(counter == 1){
                sum2 = 1;
                sum = -1;
            }

            counter2+=sum;
            counter-=1;
            row-=1;
            colum+=sum2;
        }

         counter = size;
        counter2 = 1;
        sum = 1;
        sum2 = -1;
        colum = 50;
        row = 99;
        for(i = 0; i<size*2; i++){
            auxColum = colum;
            for(j = 0; j<counter2; j++){
            
                cout<<graph[row][auxColum];
                
                auxColum+=2;
            }   
            cout<<endl;
            if(counter == 1){
                sum2 = 1;
                sum = -1;
            }

            counter2+=sum;
            counter-=1;
            row-=1;
            colum+=sum2;
        }

        sizeRow, sizeColum1, sizeColum2 = 99-((size*2)-2), 50-size, 50+size;
        
        ans = bfs();

        printf("%i\n", ans);
    }

    return 0;
}