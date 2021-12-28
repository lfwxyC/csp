#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6 + 10;
const int p = 1000000007;
int a[maxn];
ll sum[maxn];

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        set<int> s;

        for (int j = 0; j <= n; j++) {
            sum[j] = 0;
        }

        for (int j = i; j <= n; j++) {
            if (s.find(a[j]) == s.end()) {
                sum[j] = sum[j - 1] + a[j];
                sum[j] %= p;
                s.insert(a[j]);
            }
            else {
                sum[j] = sum[j - 1];
            }

            ans += sum[j];
            ans %= p;
        }
    }

    printf("%lld", ans);
    return 0;
}