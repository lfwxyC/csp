#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int n;
int a[maxn], f[maxn][2], in_deg[maxn];
int tot, head[maxn], to[maxn], nxt[maxn];

void init() {
    tot = 0;
    memset(head, 0, sizeof (head));
}

void add_edge(int u, int v) {
    tot++;
    to[tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int x, int p) {
    bool isLeaf = 1;
    f[x][1] = a[x];

    for (int i = head[x]; i; i = nxt[i]) {
        int y = to[i];

        if (y != p) {
            isLeaf = 0;
            dfs(y, x);

            f[x][0] += max(f[y][0], f[y][1]);
            f[x][1] += f[y][0];
        }
    }

    if (isLeaf) {
        f[x][0] = 0;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    init();
    memset(f, 0, sizeof (f));

    for (int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;

        add_edge(k, l);
        in_deg[l]++;
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0) {
            root = i;
            break;
        }
    }

    dfs(root, -1);
    int ans = max(f[root][0], f[root][1]);
    printf("%d", ans);
    return 0;
}