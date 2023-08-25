//https://onlinejudge.org/external/11/1197.pdf
//1197

#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

void makeSet(int node, vector<int>&father, vector<int>&range){

    father[node] = node;
    range[node] = 0;
}

int findSet(int node, vector<int>&father){

    if(node == father[node]){
        return node;
    }

    father[node] = findSet(father[node], father);
    return father[node];
}

void unionSet(int node1, int node2, vector<int>&father, vector<int>&range){

    node1 = findSet(node1, father);
    node2 = findSet(node2, father);

    if(node1 != node2){

        if(range[node2] > range[node1]){
            swap(node1, node2);
        }

        father[node2] = node1;

        if(range[node1] == range[node2]){
            range[node1]++;
        }
    }
}

int main(){

    int i, j, students, groups, size, student, pre, conj, ans;

    while(scanf("%i %i", &students, &groups) && (students || groups)){

        vector<int>father(students);
        vector<int>range(students);
        for(i = 0; i<students; i++){
            makeSet(i, father, range);
        }

        for(i = 0; i<groups; i++){
            scanf("%i", &size);
            for(j = 0; j<size; j++){
                scanf("%i", &student);
                if(j > 0){
                    unionSet(student, pre, father, range);
                }
                pre = student;
            }
        }

        conj = findSet(0, father);
        ans = 0;

        for(i = 0; i<students; i++){

            ans += (conj == findSet(i, father));
        }
        printf("%i\n", ans);
    }
    return 0;
}