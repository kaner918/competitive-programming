//https://onlinejudge.org/external/125/12582.pdf
//12582

#include<cstdio>
#include<stack>
#include<iostream>
#include<string>

using namespace std;

int letters[27];

int main(){

    int cases, i, n, letter;
    string cad;

    scanf("%i\n", &cases);

    for(i = 1; i<=cases; i++){

        getline(cin, cad);

        for(n = 0; n<27; n++){

            letters[n] = 0;
        }

        stack<int>dfs;

        for(n = 0; n<cad.length(); n++){

            letter = cad[n]-65;

            if(!dfs.size()){
                dfs.push(letter);
            }

            else{

                if(letter != dfs.top()){
                    letters[letter] = 1;
                    letters[dfs.top()]++;
                    dfs.push(letter);
                }

                else{

                    dfs.pop();
                }
            }
        }


        printf("Case %i\n", i);

        for(n = 0; n<27; n++){

            if(letters[n]){

                printf("%c = %i\n", n+65, letters[n]);
            }
        }
    }

    return 0;
}