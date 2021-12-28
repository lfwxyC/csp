#include <bits/stdc++.h>
using namespace std;

int h[300];

int main() {
    ios::sync_with_stdio(false);

    int n, m, l;
    cin >> n >> m >> l;

    for (int i = 0; i < l; i++) {
        h[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;

            h[x]++;
        }
    }

    for (int i = 0; i < l; i++) {
        printf("%d ", h[i]);
    }
}