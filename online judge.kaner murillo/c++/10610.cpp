//https://onlinejudge.org/external/106/10610.pdf
//10610

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<math.h>
#include<queue>

using namespace std;

struct Node{

    float x;
    float y;
    int pos;
    vector<int>ad;

    Node(){}
    Node(float x1, float y1, int po){

        x = x1;
        y = y1;
        pos = po;
    }
};

int bfs(int pos, float yI, float yF, map<int, Node>&grafo, map<int, bool>&visits){

    visits[pos] = true;
    queue<int> cola;
    int contador = 0;

    cola.push(pos);
    cola.push(-1);

    while(cola.size() > 1){

        pos = cola.front();
        cola.pop();
        //cout<<contador<<endl;

        if(grafo[pos].x == yI && grafo[pos].y == yF){
            
            return contador;
        }

        if(pos < 0 ){

            cola.push(-1);
            contador+=1;
        }       
        
        else{

            for(int i = 0; i<grafo[pos].ad.size(); i++){

                if(!visits[grafo[pos].ad[i]]){

                    visits[grafo[pos].ad[i]] = true;
                    cola.push(grafo[pos].ad[i]);
                }
            }
        }
    }

    return 0;
}

float distance(float x1, float y1, float x2, float y2){
    
    float num;

    num = sqrt(pow((x1-x2), 2)+pow((y1-y2),2));

    return num;
}

int main(){

    int vel, time, pos, higer;
    float nodoxI, nodoxF, nodoyI, nodoyF, x, y, dis;
    bool ans;
    string cad;

    while(scanf("%i %i", &vel, &time) && vel!= 0 || time != 0){

        pos = 0;
        scanf("%f %f\n%f %f\n", &nodoxI, &nodoxF, &nodoyI, &nodoyF);
        dis = time*60*vel;
        map<int, Node> grafo;
        map<int, bool>visits; 

        ans = false;
        
        if(distance(nodoxI, nodoxF, nodoyI,nodoyF)<=dis){

            ans = true;
        }

        else{

            grafo[pos]= Node(nodoxI, nodoxF, pos);
            visits[pos] = false;
            grafo[pos+1] = Node(nodoyI, nodoyF, pos+1);
            visits[pos+1] = false;
            pos+=2;
        }

        if(ans){

            while(getline(cin, cad) && cad!=""){

                stringstream stk(cad);

                stk>>x;
                stk>>y;

            }

            printf("Yes, visiting 0 other holes.\n");
        }

        else{

            while(getline(cin, cad) && cad!=""){

                stringstream stk(cad);

                stk>>x;
                stk>>y;
                grafo[pos] = Node(x,y,pos);
                visits[pos] = false;

                for(auto it = grafo.begin(); it!=grafo.end(); it++){
                    
                    int dis2 = distance(x, y, it->second.x, it->second.y);
                    
                    if(dis2<=dis && it->first != pos){

                        //cout<<it->first<<" "<<dis2<<endl;
                        grafo[it->first].ad.push_back(pos);
                        grafo[pos].ad.push_back(it->first);
                    }
                }

                pos+=1;
            }

            higer = bfs(0, grafo[1].x, grafo[1].y, grafo, visits);

            if(higer>0){

                printf("Yes, visiting %i other holes.\n", higer-1);
            }

            else{

                printf("No.\n");
            }
        }
    }

    return 0;
}