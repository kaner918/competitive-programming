//https://onlinejudge.org/external/126/12654.pdf
//12654

#include<cstdio>
#include<iostream>

int patches[1001], memo[1001];

using namespace std;

int dp(int index, int size, int patche1, int patche2){
    
    if(index == size){

        return 0;
    }

    else if(memo[index] != -1){
        return memo[index];
    }

    else{

        int index2 = index+1, cal = index + patche1, a;

        while(index2 < size && patches[index2] <= cal){
            index2++;
        }
        
        cout<<index2<<endl;
        a = patche1 + dp(index2, size, patche1, patche2);
        index2 = index+1;
        cal = index + patche2;

        while(index2 < size && patches[index2] <= cal){
            index2++;
        }

        memo[index] = min(a, patche2 + dp(index2, size, patche1, patche2));
        
        cout<<index<<" "<<memo[index]<<endl;

        return memo[index];
    }
}

int main(){

    int size, c, t1, t2, number, i;

    while(scanf("%i %i %i %i", &size, &c, &t1, &t2) != EOF){

        for(i = 0; i<size; i++){
            scanf("%i", &patches[i]);
            memo[i] = -1;
        }
        
        for(i = 0; i<size; i++){
            cout<<memo[i]<<" ";
        }
        cout<<endl;

        printf("%i\n", dp(0, size, t1, t2));
    }

    return 0;
}