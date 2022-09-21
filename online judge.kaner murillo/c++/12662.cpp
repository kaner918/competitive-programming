//https://onlinejudge.org/external/126/12662.pdf
//12662

#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;

int main(){


    int students, consults, left, right, pos, counter1, counter2,i;
    vector<char>vec;
    char letter;
    bool flag1, flag2, ans;

    scanf("%i", &students);

    while(students--){

        cin>>letter;
        vec.push_back(letter);
    }   

    //for(i = 0; i<vec.size(); i++){

        //cout<<vec[i]<<" ";
    //}
    scanf("%i", &consults);

    while(consults--){

        scanf("%i", &pos);

        if(vec[pos-1] != '?'){

            printf("%c\n", vec[pos-1]);
        }

        else{

            flag1 = false;
            flag2 = false;
            ans = false;

            left = pos-1;
            counter1 = 0;

            right = pos-1;
            counter2 = 0;

            while(ans == false){

                if(left>=0 && vec[left] != '?' && flag1 == false){
                    
                    flag1 = true;
                }
                
                else{

                    counter1+=1;
                }

                if(right<=vec.size()-1 && vec[right] != '?' && flag2 == false){

                    flag2 = true;

                }

                else{

                    counter2+=1;
                }

                if(flag1 == true || flag2 == true){

                    ans = true;
                }

                left-=1;
                right+=1;
            }

            if(counter1<counter2){

                for(i = 0; i<counter1; i++){

                    printf("right of ");
                }

                printf("%c\n", vec[left+1]);
            }

            else if(counter1>counter2){

                for(i = 0; i<counter2; i++){

                    printf("left of ");
                }

                printf("%c\n", vec[right-1]);
            }

            else{

                printf("middle of %c and %c\n", vec[left+1], vec[right-1]);
            }

        }
        

    }


    return 0;
}