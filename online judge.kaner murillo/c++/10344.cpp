//https://onlinejudge.org/external/103/10344.pdf
//10344

#include<cstdio>
#include<iostream>
#include<vector>

int arr[5];
using namespace std;

void makeComb(vector<vector<int>>&combs, vector<int>&aux, int index){

    if(index == 4){
        
        combs.push_back(aux);
    }
    
    else{

        int i, aux2;

        makeComb(combs, aux, index+1);

        for(i = index+1; i<5; i++){

            aux2 = aux[index]; 
            aux[index] = aux[i];
            aux[i] = aux2;
            makeComb(combs, aux, index+1);
            aux2 = aux[index]; 
            aux[index] = aux[i];
            aux[i] = aux2; 
        }
    }
}

bool solved(int res, int index, vector<int>&aux){

    if(index == 5){

        if(res == 23){
            return true;
        }

        return false;
    }

    else{


        bool ans = false;
        int i;

        ans = ans || solved(res + arr[aux[index]], index+1, aux) || solved(res - arr[aux[index]], index+1, aux) || solved(res * arr[aux[index]], index+1, aux);

        return ans;
    }
}

int main(){

    vector<vector<int>>combs;
    vector<int>aux = {0, 1, 2, 3, 4};
    makeComb(combs, aux, 0);

    while(scanf("%i %i %i %i %i", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]) && (arr[0] || arr[1] || arr[2] || arr[3] || arr[4])){

        bool ans = false;

        int i, n;

        /* for(i = 0; i<120; i++){

            for(n = 0; n<5; n++){

                cout<<combs[i][n]<<" ";
            }
            cout<<endl;
        } */

        i = 0;

        while(!ans && i<120){

            ans = solved(arr[combs[i][0]], 1, combs[i]);
            i++;
        }

        if(ans){

            printf("Possible\n");
        }

        else{

            printf("Impossible\n");
        }
    }

    return 0;
}