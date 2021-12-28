#include <bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
const int maxn = 1010;
int n, x;
int a[maxn];

int main() {
    cin >> n;

    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }

    priority_queue<pa> pq;
    for (int i = 0; i < maxn; i++) {
        if (a[i]) {
            pq.emplace(a[i], -i);
        }
    }

    pair<int, int> now;
    while (!pq.empty()) {
        now = pq.top();
        pq.pop();

        cout << -now.second << " " << now.first << "\n";
    }
    return 0;
}