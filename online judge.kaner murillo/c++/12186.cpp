//https://onlinejudge.org/external/121/12186.pdf
//12186

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int solved(vector<vector<int>>&tree, int porcentage){
    
    vector<int>visits(tree.size());
    vector<int>pre(tree.size(), -1);
    vector<int>flag(tree.size(), 0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

    q.push(make_pair(tree[0].size(), 0));
    
    int i, node, aux, counter = 0;

    for(i = 0; i<tree.size(); i++){

        if(tree[i].size()){

            visits[i] = (tree[i].size()*porcentage-1) / 100+1;
            cout<<visits[i]<<endl;

        }
    }

    while(visits[0]){
        
        node = q.top().second;
        q.pop();

        /* cout<<node<<endl; */

        if(!(tree[node].size()) && visits[pre[node]]){
            
            /* cout<<node<<" "<<visits[pre[node]]<<endl; */
            counter++;
            aux = node;

            while(pre[aux] != -1 && !visits[aux]){

                /* if(!flag[aux]){

                    flag[aux];
                } */

                if(!visits[pre[aux]]){
                    counter--;
                }

                visits[pre[aux]]--;
                /* cout<<aux<<endl; */
                aux = pre[aux];
            }
        }

        else{
            
            for(i = 0; i<tree[node].size(); i++){

                pre[tree[node][i]] = node;
                q.push(make_pair(tree[tree[node][i]].size(), tree[node][i]));
            }
        }
    }

    return counter;
}

int main(){

    int employees, porcentage, node, i;

    while(scanf("%i %i", &employees, &porcentage) && (employees || porcentage)){

        vector<vector<int>>tree(employees+1);

        for(i = 1; i<employees+1; i++){
            
            scanf("%i", &node);
            tree[node].push_back(i);
        }

        printf("%i\n", solved(tree, porcentage));
    }

    return 0;
}