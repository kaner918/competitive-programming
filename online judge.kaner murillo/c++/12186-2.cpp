//https://onlinejudge.org/external/121/12186.pdf
//12186

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int dfs(vector<vector<int>>&tree, int node, int porcentage){

    int ans = 0, i, employees;

    priority_queue<int, vector<int>, greater<int>>q;

    if(!tree[node].size()){
        ans = 1;
    }

    employees = ceil((tree[node].size()*porcentage) / 100.0);

    for(i = 0; i<tree[node].size(); i++){
        q.push(dfs(tree, tree[node][i], porcentage));
    }
    
    for(i = 0; i<employees; i++){

        ans+=q.top();
        q.pop();
    }

    return ans;
}

int main(){

    int employees, porcentage, node, i;

    while(scanf("%i %i", &employees, &porcentage) && (employees || porcentage)){

        vector<vector<int>>tree(employees+1);

        for(i = 1; i<employees+1; i++){
            
            scanf("%i", &node);
            tree[node].push_back(i);
        }

        printf("%i\n", dfs(tree, 0, porcentage));
    }

    return 0;
}