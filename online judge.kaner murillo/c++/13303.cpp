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

map<string, int>index;
map<int, string>index2;
map<string, int>counters;
map<string, map<string, int>>letters;
map<string, int>visits;

void dfs(string node, vector<int>&pre){

    if(!visits[node]){
        /* cout<<node<<endl; */
        visits[node] = 1;
        int i, size = 0;
        string mini = ""; 
        for(auto it = letters[node].begin(); it!= letters[node].end(); it++){
            if(it->second == size){
                if(counters[it->first] == counters[mini]){

                    if(it->first < mini){
                        mini = it->first;
                        size = it->second;
                    }
                }

                else if(counters[it->first] > counters[mini]){
                    mini = it->first;
                    size = it->second;
                }
            }

            else if(it->second > size){
                mini = it->first;
                size = it->second;
            }
        }
        if(mini != ""){
            pre[index[mini]] = index[node];
            dfs(mini, pre);
        }
    }
}

int main(){

    int size, i, j, counter;
    string word1, word2, line;
    while(cin>>size){
        
        cin.ignore();
        // index.clear();
        // index2.clear();        
        // counters.clear();
        // letters.clear();
        // visits.clear();
        index = map<string, int>();
        index2 = map<int, string>();
        counters = map<string, int>();
        letters = map<string, map<string, int>>();
        visits = map<string, int>();
        counter = 2;
        counters["A"] = size;
        counters["B"] = size;
        index["A"] = 0;
        index["B"] = 1;
        index2[0] = "A";
        index2[1] = "B";

        for(i = 0; i<size; i++){
            getline(cin, line);
            stringstream stk(line);

            stk>>word1;

            if(!index.count(word1)){
                index[word1] = counter;
                index2[counter++] = word1;
            }
            counters[word1]++;
            letters["A"][word1]++;
            word2 = word1;

            while(stk>>word2){

                if(!index.count(word2)){
                    index[word2] = counter;
                    index2[counter++] = word2;
                }
                counters[word2]++;
                letters[word1][word2]++;
                word1 = word2;
            }

            letters[word2]["B"]++;       
        }        

        vector<int>pre(counter+1);
        vector<string>res;
        dfs("A", pre);

        if(!visits["B"]){
            cout<<"INFINITE"<<endl;
        }

        else{
            
           
            word1 = index2[pre[1]];
            while(word1 != "A"){
                res.push_back(word1);
                word1 = index2[pre[index[word1]]];
            }

            cout<<res[res.size()-1];
            for(i = res.size()-2; i>-1; i--){
                cout<<" "<<res[i];
            }
            cout<<endl;
        }
    }

    return 0;
}