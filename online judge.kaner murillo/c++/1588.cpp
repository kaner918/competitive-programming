//https://onlinejudge.org/external/15/1588.pdf
//1588

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int comparaction(string cad1, string cad2){

    int i, n, m, size = cad1.length() + cad2.length();
    
    for(i = 0; i<cad2.length(); i++){

        if(cad2[i] != cad1[cad1.length()-1] || cad2[i] == '1' || cad1[cad1.length()-1] == '1'){

                n = i;
                m = cad1.length()-1;

                //cout<<i<<"---"<<m<<"---"<<n<<endl;

                while(n>-1 && m>-1 && (cad2[n] != cad1[m] || cad2[n] == '1' || cad1[m] == '1')){

                    n-=1;
                    m-=1;
                }

                //cout<<i<<"---"<<m<<"--+"<<n<<endl;

                if(n == -1 && m!= -1 && cad2.length() + m+1 > cad2.length() && cad2.length() + m+1 < size){
                    
                    size = cad2.length() + m+1;
                }

                else if(m == -1){
                    
                    return cad2.length();
                }
            }
        }
    
    for(i = cad2.length() - cad1.length(); i<cad2.length(); i++){

        if(cad2[i] != cad1[0] || cad2[i] == '1' || cad1[0] == '1'){

            n = i;
            m = 0;

            while(n<cad2.length() && (cad2[n] != cad1[m] || cad2[n] == '1' || cad1[m] == '1')){

                n+=1;
                m+=1;
            }

            if(n == cad2.length() && cad1.length() + i > cad2.length() && cad1.length() + i < size){
                
                size = cad1.length() + i;
            }

            else if(n == cad2.length() && cad1.length() + i == cad2.length()){
                
                return cad2.length();
            }

        }
    }

    return size;
}


int main(){

    int size;
    string cad1, cad2;

    while(getline(cin, cad1)){

        getline(cin, cad2);

        if(cad1.length() >= cad2.length()){

            size = comparaction(cad2, cad1);
        }

        else{

            size = comparaction(cad1, cad2);
        }

        printf("%i\n", size);
    }

    return 0;
}