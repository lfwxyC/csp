#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int a[maxn];

int main() {
    int n, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        ans = max(ans, abs(a[i] - a[i + 1]));
    }

    cout << ans;
    return 0;
}