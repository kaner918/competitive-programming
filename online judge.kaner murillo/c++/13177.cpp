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
        int division;

        Musician(){}
        Musician(int a, int b){

            number = a;
            division = b;
        } 

        bool operator()(Musician &a, Musician &b){

            return a.number / a.division< b.number / b.division; 
        }
};

int main(){

    int i, p, n, tikets, aux, ans;
    Musician aux2;

    while(scanf("%i %i", &p, &n) != EOF){

        priority_queue<Musician, vector<Musician>, Musician> q;

        for(i = 0; i<n; i++){

            cin >> aux;

            q.push(Musician(aux, 1));

        }
        
        tikets = p-n;

        while(tikets>0){

            aux2 = q.top();
            aux2.division ++;

            //cout<<aux2.number<<" "<<aux2.number<<endl;
            q.pop();
            
            q.push(aux2);

            tikets--;
        }

        ans = q.top().number/q.top().division;

        cout<<ans + abs(q.top().number-(ans*q.top().division))<<" "<<q.top().number<<endl;
    }

    return 0;
}