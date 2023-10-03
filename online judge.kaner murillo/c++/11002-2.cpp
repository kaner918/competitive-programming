//https://onlinejudge.org/external/110/11002.pdf
//11002

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<map>
#include<algorithm>
#include<tuple>

using namespace std;

vector<vector<int>> graph;
map<tuple<int, int, int>, int> memo;

int phi(int f, int c, int n, int sum){
    int i, ans = INT_MAX, val = graph[i][j], v1;
    if(memo.count(make_tuple(f, c, sum))){
        ans = memo[make_tuple(f, c, sum)];
    }else{
        if(f < n - 1){
            ans = min(phi(f + 1, c, n, val + sum), phi(f + 1, c, n, -val + sum), phi(f + 1, c + 1, n, val + sum), phi(f + 1, c + 1, n, -val + sum));
        }else{

        }
        memo[make_tuple(f, c, sum)] = ans;
    }
    return ans;
}

int bfs(){

    int node, coste, mini = INT_MAX, i, row, colum, auxColum;

    queue<tuple<int, int, int>>q;
    set<tuple<int, int, int>>conj;
    tuple<int, int, int>aux;

    q.push(make_tuple(graph[0][0], 0, 0));
    q.push(make_tuple(-graph[0][0], 0, 0));
    
    while(!q.empty() && mini){

        coste = get<0>(q.front());
        row = get<1>(q.front());
        colum = get<2>(q.front());

        cout<<row<<" "<<colum<<" "<<coste<<endl;

        q.pop();

        if(row == graph.size()){
            mini = (mini, abs(coste));
        }

        else{   
            for(i = 0; i<2; i++){
                
                auxColum = colum + arrColum[i];
                /* cout<<auxColum<<" "<<sizeColum1<<" "<<sizeColum2<<endl; */
                if(auxColum > sizeColum1 && auxColum < sizeColum2){
                    /* cout<<"hi"<<endl; */
                    aux = make_tuple(coste + graph[row][auxColum], row+1, auxColum);
                    if(conj.find(aux) == conj.end()){
                        q.push(aux);
                        conj.insert(aux);
                    }

                    aux = make_tuple(coste - graph[row][auxColum], row+1, auxColum);
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

    int ans, n, number, i, j, k, counter, counter2, colum, row, sum, sum2, auxColum;

    while(scanf("%i", &n) && n){
        graph.clear();
        memo.clear();
        for(i = 0; i < n; i++){
            graph.push_back(vector<int> (i + 1));
            memo.push_back(vector<int> (i + 1));
            for(j = 0; j < i + 1; j++){
                scanf("%d", &graph[i][j]);
                memo[i][j] = INT_MAX;
            }
        }
        for(i = n, k = n
        ; i <= ((n - 1) * 2); i++, k--){
            graph.push_back(vector<int>);
            memo.push_back(vector<int>);
            for(j = 0; j < k; j++){
                scanf("%d", &sum);
                graph[i].push_back(sum);
                memo[i].push_back(INT_MAX);
            }
        }
        ans = phi(0, 0, n, 0);

        printf("%i\n", ans);
    }

    return 0;
}