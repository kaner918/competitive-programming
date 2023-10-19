//https://onlinejudge.org/external/112/11297.pdf
//11297

#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int size;

vector<vector<int>>A(501, vector<int>(501));
vector<vector<pair<int, int>>>tree(501*4, vector<pair<int, int>>(501*4));

void buildY(int posX, int lX, int rX, int posY, int lY, int rY){

    if(lY == rY){

        if(lX==rX){
            tree[posX][posY] = {A[lX][lY], A[lX][lY]};
        }

        else{
            tree[posX][posY].first = max(tree[2*posX+1][posY].first, tree[2*(posX+1)][posY].first);
            tree[posX][posY].second = min(tree[2*posX+1][posY].second, tree[2*(posX+1)][posY].second);
        }
    }

    else{

        int mid = lY + ((rY-lY)>>1);
        buildY(posX, lX, rX, 2*posY+1, lY, mid);
        buildY(posX, lX, rX, 2*(posY+1), mid+1, rY); 
        tree[posX][posY].first = max(tree[posX][2*posY+1].first, tree[posX][2*(posY+1)].first);
        tree[posX][posY].second = min(tree[posX][2*posY+1].second, tree[posX][2*(posY+1)].second);
    }
}

void buildX(int lX, int rX, int pos){

    if(lX != rX){

        int mid = lX + ((rX-lX)>>1);
        buildX(lX, mid, 2*pos+1);
        buildX(mid+1, rX, 2*(pos+1));
    }

    buildY(pos, lX, rX, 0, 0, size-1);
}

pair<int, int> querieY(int posX, int posY, int LY, int RY, int lY, int rY){

    if(lY > rY){
        return {-1, INT_MAX};
    }

    else if(LY == lY && RY == rY){
        return tree[posX][posY];
    }

    else{

        int mid = LY + ((RY-LY)>>1);
        pair<int, int>pair1, pair2; 
        pair1 = querieY(posX, 2*posY+1, LY, mid, lY, min(mid, rY));
        pair2 = querieY(posX, 2*(posY+1), mid+1, RY, max(lY, mid+1), rY);

        return {max(pair1.first, pair2.first), min(pair1.second, pair2.second)};
    }
}

pair<int, int> querieX(int posX, int LX, int RX, int lX, int rX, int lY, int rY){
    
    if(lX > rX){
        return {-1, INT_MAX};
    }

    else if(lX == LX && rX == RX){
        return querieY(posX, 0, 0, size-1, lY, rY);
    }

    else{
        int mid = LX + ((RX-LX)>>1);

        pair<int, int>pair1, pair2; 
        pair1 = querieX(2*posX+1, LX, mid, lX, min(mid, rX), lY, rY);
        pair2 = querieX(2*(posX+1), mid+1, RX, max(lX, mid+1), rX, lY, rY);

        return {max(pair1.first, pair2.first), min(pair1.second, pair2.second)};
    }
}

void updateY(int posX, int lX, int rX, int posY, int lY, int rY, int y, int val){
    
    if(lY == rY){

        if(lX == rX){
            tree[posX][posY] = {val, val};
        }

        else{
            tree[posX][posY].first = max(tree[2*posX+1][posY].first, tree[2*(posX+1)][posY].first);
            tree[posX][posY].second = min(tree[2*posX+1][posY].second, tree[2*(posX+1)][posY].second);
        }
    }

    else{
        int mid = lY + ((rY-lY)>>1);

        if(y<=mid){
            updateY(posX, lX, rX, 2*posY+1, lY, mid, y, val);
        }
        else{
            updateY(posX, lX, rX, 2*(posY+1), mid+1, rY, y, val);
        }

        tree[posX][posY].first = max(tree[posX][2*posY+1].first, tree[posX][2*(posY+1)].first);
        tree[posX][posY].second = min(tree[posX][2*posY+1].second, tree[posX][2*(posY+1)].second);
    }
}

void updateX(int lX, int rX, int pos, int x, int y, int val){

    if(lX != rX){

        int mid = lX + ((rX-lX)>>1);

        if(x<=mid){
            updateX(lX, mid, 2*pos+1, x, y, val);
        }

        else{
            updateX(mid+1, rX, 2*(pos+1), x, y, val);
        }
    }
    
    updateY(pos, lX, rX, 0, 0, size-1, y, val);
}

int main(){

    int consults, i, j, lX, rX, lY, rY, val;
    char consult;
    pair<int, int>aux;

    scanf("%i", &size);

    for(i = 0; i<size; i++){
        for(j = 0; j<size; j++){
            scanf("%i", &A[i][j]);
        }
    }
    
    buildX(0, size-1, 0);
    /* for(i = 0; i<size*2; i++){
        for(j = 0; j<size*2; j++){
            cout<<tree[i][j].first<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(i = 0; i<size*2; i++){
        for(j = 0; j<size*2; j++){
            cout<<tree[i][j].second<<" ";
        }
        cout<<endl;
    } */

    scanf("%i", &consults);

    for(i = 0; i<consults; i++){
        cin.ignore();
        scanf("%c", &consult);

        if(consult == 'q'){
            scanf("%i %i %i %i", &lX, &lY, &rX, &rY);
            lX--, lY--, rX--, rY--;
            aux = querieX(0, 0, size-1, lX, rX, lY, rY);
            printf("%i %i\n", aux.first, aux.second);
        }

        else{
            scanf("%i %i %i", &lX, &lY, &val);
            lX--, lY--;
            updateX(0, size-1, 0, lX, lY, val);
        }   
    }

    return 0;
}