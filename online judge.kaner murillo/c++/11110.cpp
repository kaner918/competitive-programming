//https://onlinejudge.org/external/111/11110.pdf
//11110

#include<cstdio>
#include<iostream>

using namespace std;

int graph[100][100], visits[100][100];

int main(){

    int size, n, m, i, x;

    while(scanf("%i", &size) && size !=  0){

        for(n = 0; n<size; n++){

            for(m = 0; m<size; m++){

                graph[n][m] = size;
                visits[n][m] = 0;
            }
        }

        for(i = 1; i<size; i++){

            for(x = 0; x<size; x++){
                
                scanf("%i %i", &n, &m);
                graph[n-1][m-1] = i;

            }
        }

        for(n = 0; n<size; n++){

            for(m = 0; m<size; m++){

                cout<<graph[n][m]<<" ";
            }

            cout<<endl;
        }
    }

    return 0;
}
