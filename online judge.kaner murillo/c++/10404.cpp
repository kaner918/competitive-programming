#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int tab[1000001][2];

bool dp(int n, vector<int>& numbers) {
    int i, l, k;
    bool flag;

    tab[0][0] = 0;
    tab[0][1] = 1;

    for (i = 1; i <= n; i++) {
        for (l = 0; l < 2; l++) {
            flag = false;
            for (k = 0; k < numbers.size(); k++) {
                if (i - numbers[k] >= 0) {
                    if (!l) {
                        if (!flag) {
                            tab[i][l] = tab[i - numbers[k]][!l];
                        } else {
                            tab[i][l] |= tab[i - numbers[k]][!l];
                        }
                    } else {
                        if (!flag) {
                            tab[i][l] = tab[i - numbers[k]][!l];
                        } else {
                            tab[i][l] &= tab[i - numbers[k]][!l];
                        }
                    }
                    flag = true;
                }
            }
        }
    }

    return tab[n][0];
}

int main() {
    int size, size_numbers, i, sumi;
    bool ans;
    while (cin >> size) {
        cin >> size_numbers;
        sumi = 0;
        vector<int> numbers(size_numbers);

        for (i = 0; i < size_numbers; i++) {
            cin >> numbers[i];
        }

        ans = dp(size, numbers);
        if (ans) {
            printf("Stan wins\n");
        } else {
            printf("Ollie wins\n");
        }
    }

    return 0;
}