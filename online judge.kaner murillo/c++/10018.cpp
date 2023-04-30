//https://onlinejudge.org/external/100/10018.pdf
//10018

#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

bool compare(long long int num){

    vector<int>vec1;

    while(num>0){

        vec1.push_back(num%10);
        num/=10;
    }

    int i = 0, n = vec1.size()-1;        

    while(i < n){

        if(vec1[i] != vec1[n]){
            return false;
        }

        i++;
        n--;
    }   

    return true;
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

    int n, counter;
    long long int number1, number2;
    bool flag;

    scanf("%i", &n);    

    while(n--){

        counter = 0;
        flag = false;

        scanf("%lld", &number1);

        while(!flag){

            number2 = newNum(number1);
            number1+=number2;

            flag = compare(number1);

            counter++;
        }

        printf("%i %lld\n", counter, number1);

    }

    return 0;
}