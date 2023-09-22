//https://onlinejudge.org/external/1/118.pdf
//118

#include<cstdio>
#include<iostream>
#include<string>
#include<map>

using namespace std;

int lastx, lasty, lastOrientation, maze[52][52], arrRow[] = {1, 0, -1, 0}, arrColum[] = {0, -1, 0, 1};
map<int, char>index = {{0,'S'}, {1, 'W'}, {2, 'N'}, {3, 'E'}};
map<int, char>index2 = {{'S', 0}, {'W', 1}, {'N', 2}, {'E', 3}};

bool dfs(int sizex, int sizey, int x, int y, int orientation, int indexM, string &moviments){
    
    /* cout<<x<<" "<<y<<endl; */
    lastx = x;
    lasty = y;
    lastOrientation = orientation;

    if(indexM < moviments.length()){

        bool ans = true;

        if(moviments[indexM] == 'F'){
            int auxRow = x + arrRow[orientation], auxColum = y + arrColum[orientation];    

            if(auxRow > -1 && auxColum > -1 && auxRow < sizex+1 && auxColum < sizey+1){
                ans = ans && dfs(sizex, sizey, auxRow, auxColum, orientation, indexM+1, moviments);
            }
            else{

                /* cout<<maze[x][y]<<endl; */
                if(!maze[x][y]){
                    maze[x][y] = 1;
                    return false;
                }

                else{
                    ans  = ans && dfs(sizex, sizey, x, y, orientation, indexM+1, moviments);
                }
            }
        }

        else{

            int auxOrientation = orientation;

            if(moviments[indexM] == 'L'){
                auxOrientation-=1;
                if(auxOrientation < 0){
                    auxOrientation = 3;
                }
            }

            else{
                auxOrientation+=1;
                if(auxOrientation > 3){
                    auxOrientation = 0;
                }
            }

            ans = ans && dfs(sizex, sizey, x, y, auxOrientation, indexM+1, moviments);
        }

        return ans;
    }
    else{
        return 1;
    }
}

int main(){

    int x, y, x1, y1, i, j, flag;
    string moviments;
    char orientation;

    scanf("%i %i", &y, &x);
    
    for(i = 0; i<=x; i++){
        for(j = 0; j<=y; j++){
            maze[i][j] = 0;
        }
    }
    while(cin>>y1>>x1>>orientation){
        cin.ignore();
        getline(cin, moviments);
        flag = dfs(x, y, x-x1, y1, index2[orientation], 0, moviments);

        printf("%i %i %c",lasty, x-lastx, index[lastOrientation]);

        if(flag){
            printf("\n");
        }
        else{
            printf(" LOST\n");
        }
    }
    
    return 0;
}