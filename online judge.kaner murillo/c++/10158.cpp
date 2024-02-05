//https://onlinejudge.org/external/101/10158.pdf
//10158

#include<cstdio>
#include<iostream>
#include<vector>

int enemys[10000], friends[10000];

void makeSet(int x){
    enemys[x] = x;
    friends[x] = x;
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

    int friend1, friend2, enemy1, enemy2, flag = 1;

    friend1 = findFriend(x);
    friend2 = findFriend(y);
    enemy1 = findEnemy(x);
    enemy2 = findEnemy(y);
    
    if(friend1 != friend2){
        friends[friend2] = friend1;
        enemys[friend2] = friend1;
    }
    
    else{
        flag = 0;
    }

    return flag;
}

bool unionEnemys(int x, int y){

    int friend1, friend2, enemy1, enemy2, flag = 1;

    friend1 = findFriend(x);
    friend2 = findFriend(y);
    enemy1 = findEnemy(x);
    enemy2 = findEnemy(y);
    
    if (friend1 != friend2){
        if(enemy1 != enemy2){
            enemys[enemy2] = enemy1;
        }
    }

    else{
        flag = 0;
    }

    return flag;
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
            printf("%i\n", (findFriend(x) == findFriend(y)));
        }

        else{
            printf("%i\n", (findEnemy(x) == findEnemy(y) && findFriend(x)!=findFriend(y)));
        } 
    }   

    return 0;
}