//https://onlinejudge.org/external/5/571.pdf
//571

#include<cstdio>
#include<iostream>
#include<string>
#include<climits>
#include<set>
#include<tuple>

using namespace std;

string res;
int size, flag;
//0-> fill_b. 1->fill_a, 2-> empty_b. 3->empty_a, 4->pour_b-a, 5->pour_a-b, 6->success

void comp(int &x, int &y, int maxX, int maxY, int initX, int initY){

    if(maxX - initX> initY){

        x = initX + initY;
        y = 0;

        if(x > maxX){

            y = x - maxX;
            x = maxX;
        }
    }

    else{

        x = maxX;
        y -= (maxX- initX);
    }
}

void solved(int a, int b, int sizeA, int sizeB, int n, set<pair<int, int>>&conj, string cad){

    if(b == n){

        res = cad+='6';
        size = cad.length();
    }

    else{

        char aux = '7';

        if(cad.length()){
            aux = cad[cad.length()-1];
        }

        auto it = conj.find(make_pair(a, b));

        if(cad.length() + 1 >= size || it != conj.end()){
            return;
        }
        
        int auxA, auxB;
        conj.insert(make_pair(a, b));

        if(a<sizeA){

            solved(sizeA, b, sizeA, sizeB, n, conj, cad+'1');
        }

        if(b<sizeB){

            solved(a, sizeB, sizeA, sizeB, n, conj, cad+'0');
        }

        if(a){

            solved(0, b, sizeA, sizeB, n, conj, cad+'3');
        }

        if(b){

            solved(a, 0, sizeA, sizeB, n, conj, cad+'2');
        }


        if(a && b!=sizeB){
            
            auxA = a;
            auxB = b;

            comp(auxB, auxA, sizeB, sizeA, b, a);
            solved(auxA, auxB, sizeA, sizeB, n, conj, cad+'5');
        }

        if(b && a!=sizeA){
            auxA = a;
            auxB = b;
            comp(auxA, auxB, sizeA, sizeB, a, b);
            solved(auxA, auxB, sizeA, sizeB, n, conj, cad+'4');
        }
    }

}

int main(){

    int a, b, n, i;
    char print[7][9] = {"fill B", "fill A", "empty B", "empty A", "pour B A", "pour A B", "success"};

    while(scanf("%i %i %i", &a, &b, &n) != EOF){

        res = "";
        size = INT_MAX;
        flag = 1;
        set<pair<int, int>>conj;
        solved(0, 0, a, b, n, conj, "");

        for(i = 0; i<res.size(); i++){

            cout<<print[res[i]-48]<<endl;
        }
    }

    return 0;
}
