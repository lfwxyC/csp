#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int score, w;
        cin >> score >> w;

        ans += score * w;
    }

    ans = max(0, ans);
    printf("%d", ans);
    return 0;
}