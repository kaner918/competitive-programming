//10166
//https://onlinejudge.org/external/101/10166.pdf

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<tuple>
#include<climits>

using namespace std;

string dijkstra(vector<vector<pair<int, string>>>&graph, vector<pair<string, int>>&first, int init, int finish, string time){

    int i, node, auxNodeweight, firstCoste;
    string coste, path = "99999", auxPath, ans = "99999";
    priority_queue<tuple<string, string, int>, vector<tuple<string, string, int>>, greater<tuple<string, string, int>>>q; 
    set<tuple<int, int, string>>conj;
    sort(first.begin(), first.end());
    for(i = graph.size()-1; i>-1; i--){
        if(first[i].second == init && first[i].first >= time){
            cout<<first[i].first<<endl;
            q.push(make_tuple(first[i].first, first[i].first, init));
        }        
    }

    while(!q.empty()){

        coste = get<0>(q.top());
        node = get<2>(q.top());
        auxPath = get<1>(q.top());
        q.pop();

        if(node == finish){
            if(coste < ans){
                ans = coste;
                path = auxPath;
            }

            else if(coste == ans){
                if((auxPath[0] + auxPath[1] + auxPath[2] + auxPath[3]) > (path[0] + path[1] + path[2] + path[3])){
                    ans = coste;
                    path = auxPath;
                }
            }
        }

        else{

            for(i = 0; i<graph[node].size(); i++){
                tuple<int, int, string>auxTuple = make_tuple(node, graph[node][i].first, graph[node][i].second);
                if(!conj.count(auxTuple) || node == init){
                    if(graph[node][i].first == finish){

                        q.push(make_tuple(graph[node][i].second, auxPath + " " + graph[node][i].second, graph[node][i].first));
                        conj.insert(auxTuple);    
                    }
                    else{

                        q.push(make_tuple(graph[node][i].second, auxPath, graph[node][i].first));
                        conj.insert(auxTuple);
                    }
                }
            }   
        }        
    }

    return path;
}

int main(){

    int size, station, sizeStation, counter, i, l, j;
    string hour, finish, init, time, name;

    while(scanf("%i", &size) && size){

        cin.ignore();
        map<string, int>index;
        vector<vector<pair<int, string>>>graph(size);
        vector<pair<string, int>>first;

        counter = 0;
        for(i = 0; i<size; i++){
            getline(cin, name);
            index[name] = counter++;
        }
        
        scanf("%i", &station);

        for(i = 0; i<station; i++){
            scanf("%i", &sizeStation);
            vector<pair<string, int>>aux;
            cin.ignore();
            for(j = 0; j<sizeStation; j++){
                cin>>hour>>name;
                if(!j){
                    first.push_back({hour, index[name]});
                }
                aux.push_back({hour, index[name]});
            }

            for(j = 0; j<sizeStation-1; j++){
                for(l = j+1; l<sizeStation; l++){
                    graph[aux[j].second].push_back({aux[l].second, aux[l].first});
                }
            }
        }
        
        cin>>time>>init>>finish;
        name = dijkstra(graph, first, index[init], index[finish], time);

        if(name == "99999"){
            cout<<"No connection"<<endl;
        }
        else{
            cout<<name<<endl;
        }
    }

    return 0;
}