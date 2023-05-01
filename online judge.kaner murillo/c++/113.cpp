//https://onlinejudge.org/external/1/113.pdf
//113

#include <iostream>
#include <cmath>

using namespace std;

int main()
{   
    long double n, m;

    while(cin>>n){

        cin>>m;

        cout<<(int)round(powl(m, (1.0/n)))<<endl;
    }

    return 0;
}