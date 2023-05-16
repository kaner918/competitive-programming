//https://onlinejudge.org/external/6/628.pdf
//628

#include<vector>
#include<string>
#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

void solved(int index, map<int, vector<vector<int>>>&ouput, vector<int>&numbers, vector<int>res){

    if(index < res.size()+1){

        ouput[index].push_back(res);

        int i;

        for(i = index; i<numbers.size(); i++){
            
            res[index] = numbers[i];
            solved(index+1, ouput, numbers, res);
            res[index] -=numbers[i];   
        }
        
    }
}

int main(){

    int sizeRules, sizeWords, i, n, m, index;    
    string cad;

    while(scanf("%i\n", &sizeWords) != EOF){

        vector<string>words;
        while(sizeWords--){

            getline(cin, cad);
            words.push_back(cad);
        }
        vector<int>test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        


        scanf("%i\n", &sizeRules);
        
        while(sizeRules--){

            getline(cin, cad);
            vector<int>res(cad.length(), 0);
            vector<int>res2;
            map<int, vector<vector<int>>>ouput;

            for(i = 0; i<cad.length(); i++){

                if(cad[i] == '#'){
                    res[i] = -1;
                }
                else{
                    res2.push_back(0);
                }
            }

            solved(0, ouput, test, res2);

            for(auto it = ouput.begin(); it!=ouput.end(); it++){

                sort(it->second.begin(),it->second.end());

                if(res2.size() == res.size()){

                    for(n = 0; n<it->second.size(); n++){

                        for(i = it->second[n].size()-1; i>-1; i--){
                            cout<<it->second[n][i]<<" ";
                        }
                        cout<<endl;
                    }
                }

                else{
                    
                    for(n = 0; n<it->second.size(); n++){
                        
                        index = 0;

                        for(i = 0 ; i<it->second[n].size();){

                            if(res[index] == -1){
                                cout<<words[0];
                                index--;
                            }

                            else{

                                cout<<it->second[n][i];
                                index++;
                                i++;
                            }
                        }

                        cout<<endl;
                    }
                }
            }
        }



    }




    return 0;
}