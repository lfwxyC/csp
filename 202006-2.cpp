#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    map<int, int> u;
    while (a--) {
        int index, value;
        cin >> index >> value;

        u[index] = value;
    }

    ll ans = 0;
    while (b--) {
        int index, value;
        cin >> index >> value;

        if (u[index]) {
            ans += u[index] * value;
        }
    }

    printf("%lld", ans);
    return 0;
}