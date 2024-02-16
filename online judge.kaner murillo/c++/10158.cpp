//https://onlinejudge.org/external/101/10158.pdf
//10158

#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int enemys[10000], friends[10000], rangeF[10000];

void makeSet(int x){
    enemys[x] = x;
    friends[x] = x;
    rangeF[x] = 0;
}

int findFriend(int x){

    if(friends[x] != x){
        friends[x] = findFriend(friends[x]);
    }

    return friends[x];
}

int findEnemy(int x){
    
    if(enemys[x] != x){
        enemys[x] = findFriend(enemys[x]);
    }

    return enemys[x];
}

bool unionFriends(int x, int y){

    int conj1, conj2, enemyX, enemyY, conj3, conj4, ans = 1;

    conj1 = findFriend(x);
    conj2 = findFriend(y); 
    
    if (conj1 != conj2){
        
        enemyX = findEnemy(x);
        enemyY = findEnemy(y);

        if(enemyX != enemyY){

            if(rangeF[conj1] < rangeF[conj2]){
                swap(conj1, conj2);
            }

            friends[conj2] = conj1;
            enemys[conj2] = conj1;

            if(rangeF[conj1] == rangeF[conj2]){
                rangeF[conj1]++;
            }
        }

        else{
            ans = 0;
        }
    }

    return ans;
}

bool unionEnemys(int x, int y){

    int conj1, conj2, friendX, friendY, conj3, conj4, ans = 1;

    conj1 = findEnemy(x);
    conj2 = findEnemy(y); 
    
    if (conj1 != conj2){
        
        friendX = findFriend(x);
        friendY = findFriend(y);

        if(friendX != friendY){
            enemys[conj2] = conj1;
            friends[conj2] = conj1;
        }

        else{
            ans = 0;
        }
    }

    return ans;
}

int main(){

    int n, c, x, y, i, ans;

    scanf("%i", &n);
    
    for(i = 0; i<n; i++){

        makeSet(i);
    }

    while(scanf("%i %i %i", &c, &x, &y) && (c || x || y)){

        if(c == 1){
            if(!unionFriends(x, y)){
                printf("-1\n");
            }
        }

        else if(c == 2){
            if(!unionEnemys(x, y)){
                printf("-1\n");
            }
        }

        else if(c == 3){
            //cout<<findFriend(x) <<" "<<findFriend(y)<<endl;
            printf("%i\n", (findFriend(x) == findFriend(y)));
        }

        else{
            printf("%i\n", (findEnemy(x) == findEnemy(y) && findFriend(x)!=findFriend(y)));
        } 
    }   

    return 0;
}