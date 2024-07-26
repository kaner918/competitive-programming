//https://onlinejudge.org/external/120/12049.pdf
//12049

#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

int main(){

    int cases, j, i, n, m, num, counter;
    
    scanf("%i", &cases);
    for(i = 0; i<cases; i++){
        scanf("%i %i", &n, &m);
        counter = 0;
        map<int, int>nums1;
        map<int, int>nums2;        
        for(j = 0; j<n; j++){
            scanf("%i", &num);
            nums1[num]++;
        }
        for(j = 0; j<m; j++){
            scanf("%i", &num);
            
            nums2[num]++;
        }
        for(auto it = nums1.begin(); it!=nums1.end(); it++){
            if(it->second>nums2[it->first]){
                counter+=it->second-nums2[it->first];
            }
        }
        for(auto it = nums2.begin(); it!=nums2.end(); it++){
            if(it->second>nums1[it->first]){
                counter+=it->second-nums1[it->first];
            }
        }
        printf("%i\n", counter);
    }
    return 0;  
}