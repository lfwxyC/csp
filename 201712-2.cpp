#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++) q.emplace(i);

    int cnt = 0;
    while (q.size() > 1) {
        int now = q.front();
        q.pop();

        cnt++;
        if ((cnt % 10 == k) || (cnt % k == 0)) continue;

        q.emplace(now);
    }

    cout << q.front();
    return 0;
}