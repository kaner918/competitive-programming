//https://onlinejudge.org/external/131/13177.pdf
//13177

#include<cstdio>
#include<iostream>
#include<queue>
#include<math.h>

using namespace std;

class Musician{

    public:

        int number;
        int calculation;
        int division;

        Musician(){}
        Musician(int a, int b, int c){

            number = a;
            calculation = b;
            division = c;
        } 

        bool operator()(Musician &a, Musician &b){

            return a.calculation< b.calculation; 
        }
};

int main(){

    int i, p, n, tikets, aux, ans;
    Musician aux2;

    while(scanf("%i %i", &p, &n) != EOF){

        priority_queue<Musician, vector<Musician>, Musician> q;

        for(i = 0; i<n; i++){

            cin >> aux;

            q.push(Musician(aux, aux, 2));

        }
        
        tikets = p-n;

        while(tikets>0){

            aux2 = q.top();

            if(aux2.number % aux2.division) aux2.calculation = aux2.number / aux2.division + 1;
            else aux2.calculation = aux2.number / aux2.division;

            aux2.division ++;
            q.pop();
            
            q.push(aux2);

            tikets--;
        }

        cout<<q.top().calculation<<endl;
    }

    return 0;
}