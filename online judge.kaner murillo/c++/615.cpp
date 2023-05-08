//https://onlinejudge.org/external/6/615.pdf
//615

#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int counter2;

bool dfs(map<int, vector<int>>&tree, map<int, int>&visits, int node){

    visits[node] = 0;  
    counter2++;    

    int i;
    bool ans = true;

    for(i = 0; i<tree[node].size(); i++){

        if(visits[tree[node][i]]){
            ans = dfs(tree, visits, tree[node][i]);
            if(!ans){
                return ans;
            }
        }
        
        else{

            return false;
        }
    }

    return ans;
}
int main(){

    int a, b, counter = 0, node, index;
    string a1, b1;
    char c1;
    cin>>a1;
    
    while(cin>>b1 && (b1[0] != '-')){

        a = 0;
        index = 0;
        for(index; index<a1.length(); index++){

            a = a*10 + a1[index]-48;
        }

        b = 0;
        index = 0;
        for(index; index<b1.length(); index++){

            b = b*10 + b1[index]-48;
        }

        map<int, vector<int>>tree;
        map<int, int>flag;
        set<int>conj;

        counter++;
        tree[a].push_back(b);
        flag[a] = 0; 

        if(a!=b){

            flag[b] = 1;

        }
        conj.insert(a);
        conj.insert(b);

        while((a || b) && scanf("%i %i", &a, &b) && (a || b)){

            conj.insert(a);
            conj.insert(b);
            tree[a].push_back(b);

            if(flag.find(a) == flag.end()){
                flag[a] = 0;
            }

            if(a!=b){
                flag[b] = 1;
            }
        }

        auto it = flag.begin();

        for(; it!=flag.end() && it->second != 0; it++);

        if(flag.begin()->first == 0 && flag.size() == 1){

            printf("Case %i is a tree.\n", counter);
        }

        else if(it!=flag.end() ||  flag.size() == 1){
            
            node = it->first;
            it->second = 1;
            counter2 = 0;

            if(dfs(tree, flag, node) && counter2 == conj.size()){

                printf("Case %i is a tree.\n", counter);
            }

            else{

                printf("Case %i is not a tree.\n", counter);
            }
        }

        else{

            printf("Case %i is not a tree.\n", counter);
        }

        cin.ignore();
        scanf("%c", &c1);

        cin>>a1;
    } 

    return 0;
}