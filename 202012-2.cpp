#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int sum0[maxn], sum1[maxn];

int main() {
    ios::sync_with_stdio(false);

    int m;
    cin >> m;

    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        int y, result;
        cin >> y >> result;

        v.emplace_back(make_pair(y, result));
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= m; i++) {
        if (v[i - 1].second == 0) {
            sum0[i] = sum0[i - 1] + 1;
            sum1[i] = sum1[i - 1];
        }
        else {
            sum0[i] = sum0[i - 1];
            sum1[i] = sum1[i - 1] + 1;
        }
    }

    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (i > 1 && v[i - 2].first == v[i - 1].first) continue;

        int tmp = sum0[i - 1] + sum1[m] - sum1[i];
        if (v[i - 1].second) {
            tmp++;
        }

        if (cnt <= tmp) {
            cnt = tmp;
            ans = max(ans, v[i - 1].first);
        }
    }

    printf("%d", ans);
    return 0;
}