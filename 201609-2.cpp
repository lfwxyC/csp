#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
int n, p;
int vis[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < 20; i++) {
        vis[i] = 5;
    }

    bool can;
    while (n--) {
        cin >> p;
        can = false;
        for (int i = 0; i < 20; i++) {
            if (p <= vis[i]) {
                for (int j = 0; j < p; j++) {
                    printf("%d ", (6 - vis[i]) + i * 5);
                    vis[i]--;
                }
                printf("\n");
                can = true;
                break;
            }
        }

        if (!can) {
            for (int i = 0; i < 20; i++) {
                while (vis[i]) {
                    printf("%d ", (6 - vis[i]) + i * 5);
                    vis[i]--, p--;
                    if (p == 0) return 0;
                }
            }
        }
    }

    return 0;
}