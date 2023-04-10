//https://onlinejudge.org/external/4/429.pdf
//429

#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int bfs(vector<vector<int>>&graph, int init, int finish){

    queue<int>q;
    vector<int>dist(graph.size(), -1);

    dist[init] = 0;
    q.push(init);
    int i;

    while(!q.empty()){

        init = q.front();
        q.pop();

        if(init == finish){
            return dist[finish];
        }

        for(i = 0; i<graph[init].size(); i++){

            if(dist[graph[init][i]] == -1){

                dist[graph[init][i]] = dist[init] + 1;
                q.push(graph[init][i]);
            }
        }
    }

    return -1;
}

int main(){

    int cases, index, i, size, ans;
    string word, word1, word2, line;
    bool flag;

    scanf("%i", &cases);
    cin.ignore();

    while(cases--){
        
        index = 0;   
        map<string, int>indexs;

        while(getline(cin, word) && word != "*"){

            indexs[word] = index;
            index++;
        }

        vector<vector<int>>graph(index);

        for(auto it = indexs.begin(); it!=indexs.end(); it++){

            for(auto it2 = it; it2!=indexs.end(); it2++){

                if(it->first.length() == it2->first.length()){

                    size = 0;
                    for(i = 0; i<it->first.length(); i++){

                        if(it->first[i] != it2->first[i]){
                            size++;
                        }
                    }

                    if(size == 1){

                        graph[it->second].push_back(it2->second);
                        graph[it2->second].push_back(it->second);
                    }
                }

            }

        }

        while(getline(cin, line) && line != ""){
            
            word1 = "";
            word2 = "";
            flag = true;

            for(i = 0; i<line.length()-1; i++){
                
                if(line[i] == ' '){
                    flag = false;
                }

                if(flag){

                    word1+=line[i];
                }

                else{

                    word2+=line[i+1];
                }
            }
            
            ans = bfs(graph, indexs[word1], indexs[word2]);

            if(ans == -1){

                cout<<word1<<" "<<word2<<" "<<word1.length()<<endl;
            }

            else{

                cout<<word1<<" "<<word2<<" "<<ans<<endl;
            }
        }

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}