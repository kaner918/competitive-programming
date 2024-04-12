//https://cses.fi/problemset/task/1746

#include <cstdio>
#include <iostream>
 
using namespace std;
 
const int M = 1e9 + 7;
int arr[100002];
long long int tab[100002][102];
 
int main() {
 
    int n, m, i, j;
    long long int ans;
 
    scanf("%i %i", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }
 
    if (arr[0]) {
        tab[0][arr[0]] = 1;
    }
 
    else {
        for (i = 1; i <= m; i++) {
            tab[0][i] = 1;
        }
    }
 
    for (i = 1; i < n; i++) {
        if (!arr[i]) {
            for (j = 1; j <= m; j++) {
                tab[i][j] = (tab[i][j] + tab[i - 1][j - 1]) % M;
                tab[i][j] = (tab[i][j] + tab[i - 1][j]) % M;
 
                if (j + 1 <= m) {
                    tab[i][j] = (tab[i][j] + tab[i - 1][j + 1]) % M;
                }
            }
        } else {
            tab[i][arr[i]] = (tab[i][arr[i]] + tab[i - 1][arr[i] - 1]) % M;
            tab[i][arr[i]] = (tab[i][arr[i]] + tab[i - 1][arr[i]]) % M;
 
            if (arr[i] + 1 <= m) {
                tab[i][arr[i]] = (tab[i][arr[i]] + tab[i - 1][arr[i] + 1]) % M;
            }
        }
    }
 
    if (arr[n - 1]) {
        printf("%lld\n", tab[n - 1][arr[n - 1]]);
    } else {
        ans = 0;
        for (i = 1; i <= m; i++) {
            ans = (ans + tab[n - 1][i]) % M;
        }
        printf("%lld\n", ans);
    }
    return 0;
}