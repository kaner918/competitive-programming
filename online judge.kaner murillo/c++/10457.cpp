//https://onlinejudge.org/external/104/10457.pdf
//10457

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<cmath>
#include<set>
#include<tuple>

using namespace std;

struct State{

    int pre, speed, position, maxi, mini, maxi2;

    State(){}
    State(int pre, int speed, int position, int maxi, int maxi2, int mini){

        this->pre = pre; //guardo el predecesor de cada nodo para no devolverme, ya que uso como estado el costo maximo
        this->speed = speed; // la velocidad para esa calle
        this->position = position; // la calle
        this->maxi = maxi; // el costo maximo en este estado
        this->mini = mini; // la velocidad minima
        this->maxi2 = maxi2; //velocidad maxima
    }

    bool operator<(const State&other)const{

        return maxi > other.maxi; // ordenamos de menor a mayor teniendo en cuenta el mayor gasto de energia
    }

};

int prim(vector<vector<pair<int, int>>>&graph, int init, int finish){ // recibimos el grafo, el nodo inicial, nodo final

    priority_queue<State>q; // guardamos los estados
    set<tuple<int, int>>conj; // conjunto para evitar estados repetidos, donde tenemos el nodo donde vamos, y el costo maximo encontrado 
    tuple<int, int>aux; // tuplas que modificaremos e insertaremos en el conjunto

    int i, speed, maxi, position, auxMaxi, pre, maxi2, mini, auxMaxi2, auxMini2, p = init; // el p es el nodo inicial este para no volver a pasar por el en nigun estado
    
    for(i = 0; i<graph[init].size(); i++){ //agregamos los primeros estados, los cuales son las adyacencias del nodo inicial

        q.push(State(init, graph[init][i].first, graph[init][i].second, 0, graph[init][i].first, graph[init][i].first)); //variables mencionadas en el estruct
        conj.insert(make_tuple(graph[init][i].second, graph[init][i].first));//variables mencionadas en la linea 40
    }

    while(!q.empty()){ 

        pre = q.top().pre;
        speed = q.top().speed;
        position = q.top().position;
        maxi = q.top().maxi;
        maxi2 = q.top().maxi2;
        mini = q.top().mini; // las variables estan en el mismo orden que el struct para evitar confuciones.

        q.pop();

        if(position == finish){ // verificamos si es el nodo final, y como trabajamos siempre con el menor costo en los estados, ese sera el mejor
            
            return maxi;
        }
    

        for(i = 0; i<graph[position].size(); i++){ // recorremos las adyacencias del nodo actual

            auxMaxi = maxi; // inciamos con el mejor costo hasta el momento
            auxMini2 = mini; // la menor velocidad hasta el momento
            auxMaxi2 = maxi2; // la mayor velocidad hasta el momento

            if(graph[position][i].first < mini){  // verificamos si la nueva velociad es menor a la mas minima para ese estado

                auxMini2 = min(mini, graph[position][i].first); // actualizamos ahora al nuevo minimo
            }

            else if(graph[position][i].first > maxi2){ // verificamos si la nueva velociad es mayor a la mas maxima para ese estado

                auxMaxi2 = max(maxi2, graph[position][i].first); // actualizamos ahora al nuevo maximo
            }

            auxMaxi = abs(auxMaxi2-auxMini2); // calculamos el nuevo costo de energia, el abs es innecesario pero lo dejare asi

            aux = make_tuple(graph[position][i].second, auxMaxi); // creamos el nuevo estado

            auto it = conj.find(aux); // lo buscamos en el conjunto.

            if(it == conj.end() && graph[position][i].second != pre && graph[position][i].second != p){ // si no esta, procedemos a insertarlo y agregarlo a la cola de prioridad.

                q.push(State(position, graph[position][i].first, graph[position][i].second, auxMaxi, auxMaxi2, auxMini2));
                conj.insert(aux);

            }
        }
    }

    return 0;
}

int main(){

    int junctions, conections, i, junction1, junction2, speed, speedInit, speedFinish, queries, init, finish, aux, mini;

    while(scanf("%i %i", &junctions, &conections) != EOF){ // iteramos hasta capturar el OOF

        vector<vector<pair<int, int>>>graph(junctions); // creamos el grafo con los n junctions, primera posicion velocidad fija y segunda es la adyacencia

        for(i = 0; i<conections; i++){ // recorremos la cantidad de aristas las cuales son bidireccionales

            scanf("%i %i %i", &junction1, &junction2, &speed); // escaneamos la interseccion 1 y 2, y su velocidad fija

            graph[junction1-1].push_back(make_pair(speed, junction2-1)); // agregamos al grafo
            graph[junction2-1].push_back(make_pair(speed, junction1-1));// agregamos al grafo el inverso
        }

        scanf("%i %i", &speedInit, &speedFinish); 
        scanf("%i", &queries);

        while(queries--){ // recorremos los queries

            scanf("%i %i", &init, &finish);

            mini = prim(graph, init-1, finish-1);

            printf("%i\n", mini+speedInit+speedFinish);
            
        }
    }


    return 0;
}