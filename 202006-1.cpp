#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
struct Node {
    int x, y;
    char type;
}typedef Node;
Node node[maxn];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> node[i].x >> node[i].y >> node[i].type;
    }

    while (m--) {
        int a, b, c;
        cin >> c >> a >> b;

        bool a_up = 0, a_down = 0, b_up = 0, b_down = 0;
        for (int i = 1; i <= n; i++) {
            if (a * node[i].x + b * node[i].y + c > 0) {
                if (node[i].type == 'A') {
                    a_up = 1;
                }
                else {
                    b_up = 1;
                }
            }
            else {
                if (node[i].type == 'A') {
                    a_down = 1;
                }
                else {
                    b_down = 1;
                }
            }
        }

        if ((a_up && !a_down && !b_up && b_down) || (!a_up && a_down && b_up && !b_down)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}