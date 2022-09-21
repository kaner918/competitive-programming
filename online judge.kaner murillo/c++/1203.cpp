//https://onlinejudge.org/external/12/1203.pdf
//1203

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

struct items{

    int id;
    int tim;
    int acomulado;

    items(){}
    items(int i, int ti, int aco){

        id = i;
        tim = ti;
        acomulado = aco;
    }

    bool operator()(items &item1, items &item2){

        if(item1.acomulado == item2.acomulado){

            return item1.id>item2.id;
        }

        return item1.acomulado>item2.acomulado;
    }
};

int main(){

    string Register;
    int id, tim, counter, newTime;

    priority_queue<items, vector<items>, items> queue;

    while(cin >> Register && Register != "#"){

        cin >> id >> tim;
        queue.push(items(id, tim,tim));
    }

    scanf("%i", &counter);

    while(counter--){

        cout<<queue.top().id<<endl;
        tim = queue.top().tim;
        id = queue.top().id;
        newTime = queue.top().acomulado + queue.top().tim;
        queue.pop();
        queue.push(items(id, tim, newTime));
    }
    
    return 0;
}