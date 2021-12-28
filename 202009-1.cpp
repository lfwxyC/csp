#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int,int>> v;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        int dis = (x - a) * (x - a) + (y - b) * (y - b);
        v.emplace_back(make_pair(dis, i));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++) {
        printf("%d\n", v[i].second);
    }
    return 0;
}