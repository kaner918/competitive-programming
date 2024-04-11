//https://cses.fi/problemset/task/1745

#include<set>
#include<cstdio>
#include<iostream>

using namespace std;

int arr[102], tab[100002];

int main(){
    
    int i, j, maxi = 0, n;
    set<int>ans;
    
    scanf("%i", &n);
    for(i = 0; i<n; i++){
        scanf("%i", &arr[i]);
        maxi+=arr[i];
    }
    tab[0] = 1;
    for(i = 0; i<n; i++){
        for(j = maxi; j>=arr[i]; j--){
            tab[j]|=tab[j-arr[i]];
            if(tab[j]){
                ans.insert(j);
            }
        }
    }
    
    printf("%i\n%i", ans.size(), *ans.begin());
    set<int>::iterator it = ans.begin();
    it++;
    for(; it!=ans.end(); it++){
        printf(" %i", *it);
    }
    printf("\n");
    
    return 0;
}