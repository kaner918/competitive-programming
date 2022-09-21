//https://onlinejudge.org/external/112/11286.pdf
//11286

#include<map>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    int size, i, n, higer, counter, number;
    string combination;
    map<vector<int>, int>:: iterator it;

    while(scanf("%i", &size) && size != 0){

        map<vector<int>, int> dic;
        higer = 0;
        counter = 0;

        for(i = 0; i<size; i++){

            vector<int>vec1(5);

            for(n = 0; n<5; n++){

                scanf("%i", &number);
                vec1.push_back(number);
            }
            
            sort(vec1.begin(), vec1.end());

            if (dic.find(vec1) != dic.end()){

                dic[vec1]+=1;
            }

            else{

                dic[vec1] = 1;
            }

            if(dic[vec1] > higer){

                higer = dic[vec1];
            }
        }

        for(it = dic.begin(); it != dic.end(); it++){

            if(it->second == higer){
                counter++;
            }
        }
        
        printf("%i\n", higer*counter);

    }


    return 0;
}