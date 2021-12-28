#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int n, ans;
int h[maxn], w[maxn];

int main() {
    int a, b, c, d;
    ans = 0;
    memset(h, 0, sizeof (h));
    memset(w, 0, sizeof (w));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++) h[j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c >> d;
        for (int j = c; j < d; j++) w[j] = 1;
    }

    for (int i = 1; i < maxn; i++) {
        if (h[i] && w[i]) ans++;
    }
    cout << ans;
    return 0;
}