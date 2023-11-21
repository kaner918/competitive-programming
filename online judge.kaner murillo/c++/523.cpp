#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<climits>

using namespace std;

int ans;

vector<int> dijkstra(vector<vector<int>>&graph, vector<int>&costes, int a,  int b){

    vector<int>dist(graph.size(), INT_MAX);
    vector<int>pre(graph.size(), -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    q.push({0, a});
    dist[a] = 0;
    
    int i, first = a, coste, weight;
    
    while(!q.empty()){

        a = q.top().second;
        coste = q.top().first;
        q.pop();

        if(coste == dist[a]){

            for(i = 0; i<graph.size(); i++){
                if(i != a && graph[a][i] != -1){
                    weight = graph[a][i];
                    if(i != first && i != b){
                        weight += costes[i];
                    }

                    if(coste + weight < dist[i]){
                        dist[i] = coste + weight;
                        q.push({dist[i], i});
                        pre[i] = a;
                    }
                }
            }
        }
    }

    ans =  dist[b];
    return pre;
}

int main(){

    int cases, i, counter = 0, j, a, b, size, number;
    string line;

    cin>>cases;

    cin.ignore();
    cin.ignore();
    counter = 0;
    
    while(cases--){
        vector<vector<int>>arr;
        getline(cin, line);
        stringstream stk(line);
        arr.push_back(vector<int>());

        while(stk>>number){
            arr[0].push_back(number);            
        }

        for(i = 1; i<arr[0].size(); i++){
            arr.push_back(vector<int>());
            for(j = 0; j<arr[0].size(); j++){
                cin>>number;
                arr[i].push_back(number);
            }
        }

        vector<int>costes(arr[0].size());
        for(i = 0; i<arr[0].size(); i++){
            cin>>costes[i];
        }
        cin.ignore();
        line = "k";
        while(getline(cin, line) && line != ""){
            if(counter){
                cout<<endl;
            }
            stringstream stk(line);
            stk>>a>>b;
            a--;
            b--;
            vector<int>pre = dijkstra(arr, costes, a, b);
            cout<<"From "<<a+1<<" to "<<b+1<<" :"<<endl<<"Path: ";
            vector<int>aux;

            while(b != -1){
                aux.push_back(b);
                b = pre[b];
            } 

            for(i = aux.size()-1; i>0; i--){
                cout<<aux[i]+1<<"-->";
            }
            cout<<aux[0]+1<<endl;
            cout<<"Total cost : "<<ans<<endl;
            counter=1;
        }
    }

    return 0;
}