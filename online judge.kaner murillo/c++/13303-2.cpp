//https://onlinejudge.org/external/133/13303.pdf
//13303

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#include<climits>

using namespace std;

//lecture
map<string, int>init;
map<string, int>finish;
map<int, int>counters;
map<string, int>index;
map<int, string>index2;
map<int, vector<pair<int, int>>>letters;
vector<pair<string, int>> finish2;

//solved

int indexC, indexTps;
vector<int>tps(100001);
vector<int>indexComponent(100001);
vector<int>visits(100001);

void kosarajuAux(int node, vector<vector<int>>&graph, vector<vector<int>>&graphT){

    if(!visits[node] ){
        visits[node] = 1;
        int i, mini = INT_MAX, size = 0;

        for(i = 0; i<letters[node].size(); i++){
            if(letters[node][i].second == size){

                if(counters[letters[node][i].first] == counters[mini]){

                    if(index2[letters[node][i].first] < index2[mini]){
                        mini = letters[node][i].first;
                        size = letters[node][i].second;
                    }
                }

                else if(counters[letters[node][i].first] > counters[mini]){
                    mini = letters[node][i].first;
                    size = letters[node][i].second;
                }
            }

            else if(letters[node][i].second > size){
                mini = letters[node][i].first;
                size = letters[node][i].second;
            }
        }
        if(mini != INT_MAX){
            graph[node].push_back(mini);
            graphT[mini].push_back(node);
            kosarajuAux(mini, graph, graphT);
        }

        if(finish[index2[node]]){
            finish2.push_back({index2[node], finish[index2[node]]});
        }

        tps[indexTps--] = node;
    }
}

void asing(int u, int v, vector<vector<int>>&graphT){
    indexComponent[u] = v;
    int i;

    for(i = 0; i<graphT[u].size(); i++){
        if(indexComponent[graphT[u][i]] == -1){
            asing(graphT[u][i], v, graphT);
        }
    }
}

void kosaraju(int size, vector<vector<int>>&graph, vector<vector<int>>&graphT){

    int i;

    for(i = 0; i<size; i++){
        kosarajuAux(i, graph, graphT);
    }

    for(i = 0; i<size; i++){
        if(indexComponent[tps[i]] == -1){
            indexC++;
            asing(tps[i], tps[i], graphT);
        }
    }
}

void dfs(int node, vector<vector<int>>&graph){

    if(!visits[node]){
        visits[node] = 1;
        int i;

        for(i = 0; i<graph[node].size(); i++){
            dfs(graph[node][i], graph);
        }
    }
}

bool comp(pair<int, int>&a, pair<int, int>&b){

    if(a.second == b.second){
        if(counters[a.first] == counters[b.first]){
            return index2[a.first] < index2[b.first];
        }
        return counters[a.first] > counters[b.first];
    }
    return a.second>b.second;
}

bool comp2(pair<string, int>&a, pair<string, int>&b){

    if(a.second == b.second){
        if(counters[index[a.first]] == counters[index[b.first]]){
            return a.first < b.first;
        }
        return counters[index[a.first]] > counters[index[b.first]];

    }
    return a.second>b.second;
}

int main(){

    int size, i, j, counter, counter2, flag;
    string word, word2, line;
    map<string, int>wordx;

    while(cin>>size){
        cin.ignore();
        counter = 0;
        init.clear(); // elements that initialit the lines
        finish.clear(); //elements that finish the lines
        finish2.clear();
        index.clear();
        index2.clear();
        counters.clear();
        letters.clear();

        for(i = 0; i<size; i++){
            getline(cin, line);
            stringstream stk(line);
            stk>>word;
            flag = 0;
            init[word]++;
            if(!index.count(word)){
                index[word] = counter;
                indexComponent[counter] = -1;
                tps[counter] = -1;
                visits[counter] = 0;
                index2[counter++] = word;
            }
            counters[index[word]]++;
            wordx[word] = 1;
            word2 = word;
            while(stk>>word2){
                wordx[word2] = 1;
                if(!index.count(word2)){
                    index[word2] = counter;
                    indexComponent[counter] = -1;
                    tps[counter] = -1;
                    visits[counter] = 0;
                    index2[counter++] = word2;
                    
                }
                counters[index[word2]]++;
                flag = 0;
                for(j = 0; j<letters[index[word]].size() && !flag; j++){
                    if(letters[index[word]][j].first == index[word2]){
                        letters[index[word]][j].second++;
                        flag = 1;
                    }
                }

                if(!flag){
                    letters[index[word]].push_back({index[word2], 1});
                }
                word = word2;
            }

            flag = 0;
            finish[word]++;
        }   

        /* for(auto it = wordx.begin(); it!=wordx.end(); it++){
            cout<<it->first<<" ";
        }
        cout<<endl; */
        vector<pair<string, int>> init2(init.begin(), init.end());
        /* vector<pair<string, int>> finish2(finish.begin(), finish.end()); */
        sort(init2.begin(), init2.end(), comp2);
        sort(finish2.begin(), finish2.end(), comp2);
        /* for(auto it = letters.begin(); it!=letters.end(); it++){

            cout<<"hi mr: "<<index2[it->first]<<endl;

            for(i = 0; i<it->second.size(); i++){
                cout<<index2[it->second[i].first]<<" "<<it->second[i].second<<endl;
            }
        } */

        vector<vector<int>>graph(counter);
        vector<vector<int>>graphT(counter);
        indexC = 0;
        indexTps = counter-1;

        kosaraju(counter, graph, graphT);
        for( i = 0; i<counter; i++){
            visits[i] = 0;
        }

        counter2 = 0;
     
        dfs(index[init2[0].first], graph);
        
        if(indexComponent[index[init2[0].first]] != indexComponent[index[finish2[0].first]] && !visits[index[finish2[0].first]]){
            cout<<"INFINITE"<<endl;
        }

        else if(indexComponent[index[init2[0].first]] == indexComponent[index[finish2[0].first]] && finish[init2[0].first]){
            cout<<init2[0].first<<endl;
        }
        
        else{
            cout<<init2[0].first;
            word = init2[0].first;
            while(word != finish2[0].first){
                word = index2[graph[index[word]][0]];
                cout<<" "<<word;
            }
            cout<<endl;
        }
    }

    return 0;
}