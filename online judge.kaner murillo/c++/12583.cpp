//https://onlinejudge.org/external/125/12583.pdf
//12583

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    int cases, i, days, time, auxTime, n, m, counter;
    string cad;
    bool ans;

    scanf("%i", &cases);

    for(i = 1; i<cases+1; i++){

        cin>>days>>time>>cad;
        counter = 0;

        for(n = 0; n<days; n++){

            auxTime = 1; 
            m = n+1;
            ans = true;
            
            while(m < days && auxTime <= time && ans == true){

                if(auxTime<= time && cad[m] == cad[n] && ans == true){

                    counter++;
                    ans = false;
                }
                
                auxTime++;
                m++;
            }

        }

        printf("Case %i: %i\n", i, counter);

    }

    return 0;
}