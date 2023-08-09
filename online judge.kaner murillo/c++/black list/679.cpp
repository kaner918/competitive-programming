#include <iostream>
#include <vector>

using namespace std;

int main() {
    int depth, label, level, act, pre, i, n, cases;
    cin >> cases;

    while (cases != -1) {
        vector<bool> flags(524288, false);
        vector<bool> flags2(524288, -1);

        for (i = 0; i < cases; i++) {
            
            cin >> depth >> label;

            for (n = 0; n < label; n++) {
                level = 1;
                act = 1;
                pre = -1;

                while (level != depth) {
                    pre = act;

                    if (!flags[act] || flags2[act] != i) {
                        act = act * 2;
                    } else {
                        act = act * 2 + 1;
                    }

                    flags[pre] = !flags[pre];
                    flags2[pre] = i;
                    level++;
                }
            }

            cout << act << endl;
        }

        cin >> cases;
    }

    return 0;
}
