//https://onlinejudge.org/external/131/13181.pdf
//13181

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(){

    int low, hight, counter, higer;
    string cad;

    while(getline(cin, cad)){

        higer = 0;
        counter = 0;
        low = 0;
        hight = cad.length()-1;

        if(cad[low] == '.'){

            while(cad[low+1] == '.'){
                counter++;
                low++;
            }

            higer = counter;
            counter = 0;
        }

        if(cad[hight] == '.'){

            while(cad[hight-1] == '.'){
                counter++;
                hight--;
            }

            higer = max(counter, higer);
            counter = 0;
        }

        low++;

        while(low <= hight){

            if(cad[low] == '.'){
                counter++;
            }

            else{

                higer = max(higer, (counter-(!((counter)%2)))/2);
                counter = 0;
            }

            low++;
        }

        printf("%i\n", higer);
    }

    return 0;
}