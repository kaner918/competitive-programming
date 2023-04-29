//https://onlinejudge.org/external/100/10018.pdf
//10018

#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int index(long long int number){

    if(number<10){

        return 0;
    }

    else if(number<100){

        return 1;
    }

    else if(number<1000){

        return 2;
    }

    else if(number<10000){

        return 3;
    }

    else if(number<100000){

        return 4;
    }

    else if(number<1000000){

        return 5;
    }

    else if(number<10000000){

        return 6;
    }

    else if(number<100000000){

        return 7;
    }

    else if(number<1000000000){

        return 8;
    }

    return 9;
}

long long int newNum(long long int num){

    long long int num2 = 0;

    while(num>0){

        num2 = num2 * 10 + num%10;
        num/=10;
    }

    return num2;
}

int main(){

    int x, y, n, div1, div2, counter;
    long long int number1, number2;
    bool flag, flag2;

    scanf("%i", &n);    

    while(n--){

        counter = 0;
        flag = false;

        scanf("%lld", &number1);

        while(!flag){


            number2 = newNum(number1);
            number1+=number2;

            x = 0;
            div1 = 10;
            y = index(number1);
            div2 = pow(10, y);
            flag2 = true;

            cout<<number1<<" "<<number2<<endl;

            while(x<y && flag2){

                cout<<x<<" "<<y<<endl;
                cout<<number1/div2<<" "<<number1%div1<<endl;

                if(number1/div2 != number1%div1){

                    flag2 = false;
                }

                else{
                    y--;
                    x++;
                    div1*=10;
                    div2/=10;
                }
            }

            if(x >= y){
                flag = true;
            }

            counter++;
        }

        printf("%i %lld\n", counter, number1);

    }

    return 0;
}