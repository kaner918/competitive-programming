#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

int main(){

    int cases, problems, b, d, i, j, sum;
    bool ans;

    scanf("%i", &cases);

    while(cases--){

        scanf("%i", &problems);

        if(problems >= 10){

            vector<int>vec1(10, 0);
            sum = 0;
            ans = true;

            for(i = 0; i<problems; i++){

                scanf("%i %i", &b, &d);

                if(vec1[d-1] < b){
                    
                    vec1[d-1] = b;
                }
            }

            for(i = 0; i<10; i++){

                if(vec1[i]){

                    sum+=vec1[i];
                }

                else{

                    printf("MOREPROBLEMS\n");
                    ans = false;
                    break;
                }

            }

            if(ans){

                printf("%i\n", sum);
            }
        }

        else{
            
            for(i = 0; i<problems; i++){

                scanf("%i %i", &d, &d);
            }
            
            printf("MOREPROBLEMS\n");
        }
    }

    return 0;
}