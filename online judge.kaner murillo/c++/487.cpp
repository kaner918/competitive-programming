//https://onlinejudge.org/external/4/487.pdf
//487

#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

char letters[21][21];
int arrRow[] = {1, 1, 1, 0, -1, -1, -1, 0}, arrColum[] = {1, 0, -1, -1, -1, 0, 1, 1};

void solved(vector<string>&res, int size, int row, int colum, string word){

    if(word.length() > 2){

        res.push_back(word);
    }

    int i, auxRow, auxColum;

    for(i = 0; i<8; i++){

        auxRow = row + arrRow[i];
        auxColum = colum + arrColum[i];

        if(auxRow > -1 && auxColum > -1 && auxRow < size && auxColum < size && letters[auxRow][auxColum] > word[word.length()-1]){

            solved(res, size, auxRow, auxColum, word+letters[auxRow][auxColum]);
        }
    }
}

bool compare(string a, string b){
    
    if(a.length()!=b.length()){
        return a.length()<b.length();
    }

    else{

        int i;

        for(i = 0; i<a.length(); i++){

            if(a[i]<b[i]){
                return true;
            }

            else if(a[i]>b[i]){
                return false;
            }
        }
    }
    
    return a.length()<b.length();
}

int main(){

    int cases, size, i, n, m;

    scanf ("%i", &cases);

    while(cases--){

        cin.ignore();
        scanf("%i,", &size);
        vector<string>res;

        for(n = 0; n<size; n++){

            cin.ignore();

            for(m = 0; m<size; m++){

                scanf("%c", &letters[n][m]);
            }
        }

        for(n = 0; n<size; n++){

            for(m = 0; m<size; m++){

                solved(res, size, n, m, "");
            }
        }

        sort(res.begin(), res.end(), compare);

        if(res.size()){

            cout<<res[0]<<endl;
            for(n = 1; n<res.size(); n++){
                if(res[n] != res[n-1]){

                    cout<<res[n]<<endl;
                }
            }
        }
        if(cases>0){
        printf("\n");
        }
    }

    return 0;
}