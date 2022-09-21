//https://onlinejudge.org/external/109/10940.pdf
//10940

#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int main(){

    int size, i, aux;

    while(scanf("%i", &size) && size != 0){

        queue<int>q;

        for(i = 0; i<size; i++){

            q.push(i+1);
        }

        while(q.size()>1){

            q.pop();
            aux = q.front();
            q.push(aux);
            q.pop();
        }

        aux = q.front();
        printf("%i\n", aux);
    }


    return 0;
}