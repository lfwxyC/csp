#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;

        cnt += w;
        if ((cnt >= k) || (i == n - 1)) {
            ans++;
            cnt = 0;
        }
    }

    cout << ans;
    return 0;
}