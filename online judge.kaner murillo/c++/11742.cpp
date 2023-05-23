//https://onlinejudge.org/external/117/11742.pdf
//11742

#include<cstdio>
#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

void makeComb(vector<vector<int>>&combs, vector<int>&comb, int index){

    if(index == comb.size()){

        combs.push_back(comb);
    }

    else{

        int i, aux;
        makeComb(combs, comb, index+1);

        for(i = index+1; i<comb.size(); i++){
            swap(comb[index], comb[i]);
            makeComb(combs, comb, index+1);
            swap(comb[index], comb[i]);
        }
    }
}

int main(){ 

    int group, constraint, i, n, m, j, fine, a, b, c;
    bool flag, flag2, flag3;

    while(scanf("%i %i", &group, &constraint) && (group || constraint)){

        vector<int>comb;
        vector<vector<int>>combs;
        vector<tuple<int, int, int>>constraints;

        for(i = 0; i<group; i++){
            comb.push_back(i);
        }

        while(constraint--){
            scanf("%i %i %i", &a, &b, &c);  
            constraints.push_back(make_tuple(a, b, c));
        }

        makeComb(combs, comb, 0);
        fine = combs.size();

        for(i = 0; i<combs.size(); i++){

            flag = true;

            for(n = 0; n<constraints.size() && flag; n++){
                
                flag3 = false;

                for(m = 0; m<combs[i].size() && flag && !flag3; m++){

                    if(combs[i][m] == get<0>(constraints[n]) || combs[i][m] == get<1>(constraints[n])){
                        
                        if(combs[i][m] == get<0>(constraints[n])){
                            a = get<0>(constraints[n]);
                            b = get<1>(constraints[n]);
                        }

                        else{
                            b = get<0>(constraints[n]);
                            a = get<1>(constraints[n]);
                        }

                        flag2 = false;
                        flag3 = true;

                        if(get<2>(constraints[n]) > 0){

                            for(j = 0; j<get<2>(constraints[n])+1 && m+j<combs[i].size(); j++){
                                if(combs[i][m+j] == b){
                                    flag2 = true;
                                }
                            }
                        } 

                        else{

                            for(j = (m+get<2>(constraints[n])*-1); j<combs[i].size(); j++){
                                if(combs[i][j] == b){
                                    flag2 = true;
                                }
                            }
                        }

                        flag = flag2;
                    }
                }
            }

            if(!flag){
                fine--;
            }
        }

        printf("%i\n", fine);
    }

    return 0;
}