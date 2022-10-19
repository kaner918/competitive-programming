//https://onlinejudge.org/external/1/168.pdf
//1689

#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int sum, max1, posArr;
char res[27], last1;
bool ans;

void dfs(char pos, char these, map<char, vector<char>>&graph, map<char, int>&position, vector<int>&visits){

    int i;
    
    if(sum == max1){

        visits[position[these]] = true;
        res[posArr] = these;
        posArr++;
        sum = 0;
    }

    for(i = 0; i<graph[pos].size(); i++){

        if(visits[position[graph[pos][i]]] == false && graph[pos][i] != these && ans == true){

            sum++;
            dfs(graph[pos][i], pos, graph, position, visits);
        
        }       
    }

    if(ans == true){

        last1 = pos;
        ans = false;
    }
}

int main(){

    int i, n, wCandles, counter, movements;
    string line, num;
    char mino, these, last;
    bool flag;

    while(getline(cin, line) && line != "#"){
        
        i = 0;
        flag = true;
        num = "";
        map<char, vector<char>>graph;
        map<char, int>position;

        counter = 0;

        while(line[i] != '.'){
            
            if(line[i] == ':'){

                flag = false;
            }

            if(flag == true && line[i] != ':' && line[i] != ';'){
                
                map<char, vector<char>>::iterator it = graph.begin();
                for(; it != graph.end() && it->first!=line[i]; it++);

                if(it == graph.end()){

                    graph[line[i]];
                    position[line[i]] = counter;
                    counter++;
                }
                last = line[i];
            }

            else if(line[i] != ';' && line[i] != ':'){

                map<char, vector<char>>::iterator it = graph.begin();
                for(; it != graph.end() && it->first!=line[i]; it++);

                graph[last].push_back(line[i]);

                if(it==graph.end()){

                    graph[line[i]];
                    position[line[i]] = counter;
                    counter++;
                }
            }

            else if(line[i] == ';'){

                flag = true;
            }

            i++;
        }
        
        mino = line[i+2];
        these = line[i+4];
        sum = 0;
        posArr = 0;

        for(i = i+6; i<line.size(); i++){

            num+=line[i];
        }

        max1 = stoi(num);

        vector<int>visits(counter, false);
        ans = true;

        dfs(mino, these, graph, position, visits);
        
        for(i = 0; i<posArr; i++){

            cout<<res[i]<<" ";
        }

        cout<<"/"<<last1<<endl;
    }

    return 0;
}
