//https://onlinejudge.org/external/130/13015.pdf
//13015

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int main(){

    int A, B, employees, precedence, employe1, employe2, ans, i;

    while(scanf("%i %i %i %i", &A, &B, &employees, &precedence) != EOF){

        vector<vector<int>>graph(employees);
        vector<int>roots(employees, 0);
        vector<int>visits(employees, -1);

        while(precedence--){

            scanf("%i %i", &employe1, &employe2);

            graph[employe1].push_back(employe2);
            roots[employe2] = -1; //cambiamos el estado a -1, ya que al ser un nodo que se puede visitar, no es una raiz
        }

    }
    return 0;
}