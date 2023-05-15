//https://onlinejudge.org/external/5/598.pdf
//598

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>

using namespace std;

void solved(map<int, vector<string>>&res, vector<string>&cads, int size, int last, int low, int hight, string cad){

    if(size>= low){

        auto it = res.find(size-low);

        if(it == res.end()){
            res[size-low] = {cad};
        }

        else{
            if(!(res[size-low].size()) || (res[size-low].size() && res[size-low].back() != cad)){
                res[size-low].push_back(cad);
            }
        }
        /* if(!(res[size-low]s.ize()) || (res[size-low].size() && res[size-low].back() != cad)){
            res[size-low].push_back(cad);
        } */
    }

    if(size+1>hight || last+1 == cads.size()){
        return;
    }   

    int i;
    string aux = "", aux2;
    solved(res, cads, size, last+1, low, hight, cad);

    if(cad.length()){
        aux = ", "; 
    }            

    /* aux2 = to_string(last+1); */

    solved(res, cads, size+1, last+1, low, hight, cad+aux+cads[last+1]);
    

};

int main(){

    int cases, a, b, i, aux, n;
    scanf("%i\n", &cases);
    string cad, line;

    while(cases--){
        
        getline(cin, line);

        vector<string>cads;
        cads.push_back("");

        while(getline(cin, cad) && cad != ""){
            cads.push_back(cad);
        }

        b = -1;

        if(line == "*"){
            a = 1;
            b = cads.size();
        }

        else{

            stringstream stk(line);
            stk>>a;
            aux = a;

            while(stk>>a){
                b = a;
                a = aux;
            }

            if(b == -1){
                b = a;
            }
        }
        
        /* vector<vector<string>>res(0); */
        map<int, vector<string>>res;
        
        solved(res, cads, 0, 0, a, b, "");
        auto it = res.begin();

        for(; it!=res.end(); it++){
            
            if(it->second.size()){

                printf("Size %i\n", a++);
                for(n = it->second.size()-1; n>-1; n--){
                    cout<<it->second[n]<<endl;
                }

                printf("\n");    //only comprobar
            }
        }

        if(cases>0){
            printf("\n");
        }
    }

    return 0;
}