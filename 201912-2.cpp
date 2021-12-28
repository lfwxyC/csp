#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;

    bool operator < (const Point & p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
}typedef Point;

int n;
map<Point, int> mp;

int main() {
    cin >> n;

    queue<Point> q;
    for (int k = 1; k <= n; k++) {
        Point p;
        cin >> p.x >> p.y;

        mp[p] = 1;
        q.emplace(p);
    }

    int a[5];
    memset(a, 0, sizeof(a));

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        int cnt = 0;
        q.pop();

        Point p1 = {x, y + 1}, p2 = {x, y - 1}, p3 = {x + 1, y}, p4 = {x - 1, y};
        Point q1 = {x - 1, y - 1}, q2 = {x - 1, y + 1}, q3 = {x + 1, y - 1}, q4 = {x + 1, y + 1};

        if (mp[p1] && mp[p2] && mp[p3] && mp[p4]) {
            if (mp[q1]) cnt++;

            if (mp[q2]) cnt++;

            if (mp[q3]) cnt++;

            if (mp[q4]) cnt++;

            a[cnt]++;
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}