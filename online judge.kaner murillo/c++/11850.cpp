//https://onlinejudge.org/external/118/11850.pdf
//11850

#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    int stations, i, num, aux;

    while(scanf("%i", &stations) && stations != 0){

        vector<int>vecStations;

        bool ans = true;

            for(i = 0; i<stations; i++){

                scanf("%i", &num);
                vecStations.push_back(num);

            }

        if(stations >= 8){

            sort(vecStations.begin(), vecStations.end());

            for(i = 0; i<stations-1; i++){

                if(vecStations[i+1] -  vecStations[i] > 200){

                    ans = false;
                }
            }
            
            aux = (1422 - vecStations.back())*2;

            if(ans == true && vecStations[vecStations.size()-1] - vecStations[vecStations.size()-2]<=200  && aux <= 200 && vecStations[vecStations.size()-1]>=1122){

                printf("POSSIBLE\n");
            }

            else{

                printf("IMPOSSIBLE\n");
            }
        }

        else{

            printf("IMPOSSIBLE\n");
            
        }
    }

    return 0;
}