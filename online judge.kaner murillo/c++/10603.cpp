//https://onlinejudge.org/external/106/10603.pdf
//10603

#include<queue>
#include<vector>
#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
#include<tuple>

using namespace std;

struct State{

    int a, b, c, coste;
    State(){}
    State(int a, int b, int c, int coste){

        this->a = a;
        this->b = b;
        this->c = c;
        this->coste = coste;
    }

    bool operator < (const State &other) const{

        return coste > other.coste;
    }
};

void comp(int &x, int &y, int maxX, int maxY, int initX, int initY, int &w){

    if(maxX - initX> initY){

        x = initX + initY;
        w += initY;
        y = 0;

        if(x > maxX){

            y = x - maxX;
            x = maxX;
            w-=y;
        }
    }

    else{

        x = maxX;
        w += (maxX - initX);
        y -= (maxX- initX);
    }
}

void dijkstra(int a, int b, int c, int d, int &movements, int &water){

    set<tuple<int, int, int>>conj;
    set<tuple<int, int, int>>::iterator it;
    priority_queue<State>q;

    q.push(State(0, 0, c, 0));
    conj.insert(make_tuple(0, 0, c));
    int coste, a2, b2, c2, a3, b3, c3, w;
    bool flag = false;

    tuple<int, int, int>comb;

    while(!q.empty() && !flag){

        a2 = q.top().a;
        b2 = q.top().b;
        c2 = q.top().c;
        coste = q.top().coste;

        q.pop();

        if(a2 == d || b2 == d || c2 == d){

            movements = coste;
            water = d;
            flag = true;
        }

        if(a2 > -1 && a2 <d && a2 > water){

            movements = coste;
            water = a2;

        }

        if(b2 > -1 && b2 <d && b2 > water){

            movements = coste;
            water = b2;
            
        }

        if(c2 > -1 && c2 <d && c2 > water){

            movements = coste;
            water = c2;
            
        }

        if(!flag){

            if(b2 || c2){
                
                a3 = a2;
                b3 = b2;
                c3 = c2;
                w = coste;

                comp(a3, b3, a, b, a2, b2, w);

                comb = make_tuple(a3, b3, c);

                it = conj.find(comb);

                if(it == conj.end()){

                    conj.insert(comb);
                    q.push(State(a3, b3, c2, w));
                }

                a3 = a2;
                w = coste;

                comp(a3, c3, a, b, a2, c2, w);

                comb = make_tuple(a3, b2, c3);

                it = conj.find(comb);

                if(it == conj.end()){

                    conj.insert(comb);
                    q.push(State(a3, b2, c3, w));
                }
            }

            if(a2 || c2){
                

                a3 = a2;
                b3 = b2;
                c3 = c2;
                w = coste;

                comp(b3, a3, b, a, b2, a2, w);

                comb = make_tuple(a3, b3, c2);

                it = conj.find(comb);

                if(it == conj.end()){

                    conj.insert(comb);
                    q.push(State(a3, b3, c2, w));
                }

                b3 = b2;
                w = coste;
                
                comp(b3, c3, b, c, b2, c2, w);

                comb = make_tuple(a2, b3, c3);

                it = conj.find(comb);

                if(it == conj.end()){

                    conj.insert(comb);
                    q.push(State(a2, b3, c3, w));
                }
            }

            if(a2 || b2){
                
                a3 = a2;
                b3 = b2;
                c3 = c2;
                w = coste;
                comp(c3, a3, c, a, c2, a2, w);

                comb = make_tuple(a3, b2, c3);

                it = conj.find(comb);

                if(it == conj.end()){

                    conj.insert(comb);
                    q.push(State(a3, b2, c3, w));
                }

                c3 = c2;
                w = coste;

                comp(c3, b3, c, b, c2, b2, w);

                comb = make_tuple(a2, b3, c3);

                it = conj.find(comb);

                if(it == conj.end()){

                    conj.insert(comb);
                    q.push(State(a2, b3, c3, w));
                }
            }
        }
    }    
}

int main(){

    int cases, a, b, c, d, movements, water;
    
    scanf("%i", &cases);

    while(cases--){
        
        water = 0;
        movements = 0;

        scanf("%i %i %i %i", &a, &b, &c, &d);

        if(d){

            dijkstra(a, b, c, d, movements, water);
        }

        printf("%i %i\n", movements, water);
    }

    return 0;
}