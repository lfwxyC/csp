#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int ca, cb, n;
vector<int> opt;
bool vis[N][N];

struct Status {
    int pa, pb;
    int pre_opt;
};
Status st[N][N];

void dfs(int a, int b) {
    if (a == 0 && b == 0) {
        return;
    }

    opt.emplace_back(st[a][b].pre_opt);
    int pa = st[a][b].pa, pb = st[a][b].pb;
    dfs(pa, pb);
}

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(make_pair(0, 0));
    vis[0][0] = 1;
    st[0][0] = {-1, -1, 0};
    int ta;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        if (now.second == n) {
            ta = now.first;
            break;
        }

        if (now.first < ca && !vis[ca][now.second]) {
            vis[ca][now.second] = 1;
            st[ca][now.second] = {now.first, now.second, 1};
            q.emplace(make_pair(ca, now.second));
        }

        if (now.second < cb && !vis[now.first][cb]) {
            vis[now.first][cb] = 1;
            st[now.first][cb] = {now.first, now.second, 2};
            q.emplace(make_pair(now.first, cb));
        }

        if (now.first && !vis[0][now.second]) {
            vis[0][now.second] = 1;
            st[0][now.second] = {now.first, now.second, 3};
            q.emplace(make_pair(0, now.second));
        }

        if (now.second && !vis[now.first][0]) {
            vis[now.first][0] = 1;
            st[now.first][0] = {now.first, now.second, 4};
            q.emplace(make_pair(now.first, 0));
        }

        int sub = min(ca - now.first, now.second);
        if (sub && !vis[now.first + sub][now.second -sub]) {
            vis[now.first + sub][now.second - sub] = 1;
            st[now.first + sub][now.second - sub] = {now.first, now.second, 5};
            q.emplace(make_pair(now.first + sub, now.second - sub));
        }

        sub = min(now.first, cb - now.second);
        if (sub && !vis[now.first - sub][now.second + sub]) {
            vis[now.first - sub][now.second + sub] = 1;
            st[now.first - sub][now.second +sub] = {now.first, now.second, 6};
            q.emplace(make_pair(now.first - sub, now.second + sub));
        }
    }

    dfs(ta, n);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> ca >> cb >> n;

        opt.clear();
        memset(vis, 0, sizeof(vis));

        bfs();
        printf("%d ", opt.size());

        for (int i = opt.size() - 1; i >= 0; i--) {
            printf("%d ", opt[i]);
        }
    }

    return 0;
}