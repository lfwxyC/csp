#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
const int maxs = 10010;

int q, m, n, s, k, num, id;
string str;
bool can;

vector<int> G[maxn];
vector<int> topo;
string func[maxn];
int status[maxn];
int output[maxs][510];
int in_deg[maxn];

int get_index() {
    string ss = "";
    for (int i = 1; i < str.length(); i++) {
        ss += str[i];
    }
    int index = stoi(ss);

    if (str[0] == 'I') return index;
    return index + m;
}

void add_edge(int u, int v) {
    G[u].emplace_back(v);
}

void handle_status(int i) {
    if (func[i] == "AND" || func[i] == "NAND") {
        status[i] = 1;
    }
    else if (func[i] == "OR" || func[i] == "XOR" || func[i] == "NOR") {
        status[i] = 0;
    }
}

bool toposort() {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n + m; i++) {
        if (in_deg[i] == 0) {
            pq.emplace(i);
        }
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        topo.emplace_back(u);

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];

            in_deg[v]--;
            if (in_deg[v] == 0) {
                pq.emplace(v);
            }
        }
    }

    if (topo.size() < n + m) return false;
    return true;
}

void solve() {
    for (auto x:topo) {
        if (func[x] == "NAND" || func[x] == "NOR") {
            status[x] = !status[x];
        }

        for (int i = 0; i < G[x].size(); i++) {
            int v = G[x][i];

            if (func[v] == "NOT") {
                status[v] = !status[x];
            } else if (func[v] == "AND" || func[v] == "NAND") {
                status[v] &= status[x];
            } else if (func[v] == "OR" || func[v] == "NOR") {
                status[v] |= status[x];
            } else if (func[v] == "XOR") {
                status[v] ^= status[x];
            }
        }
    }
}

void reset() {
    topo.clear();

    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }
}

int main() {
    cin >> q;

    while(q--) {
        cin >> m >> n;

        reset();

        int i;
        for (i = 1; i <= m; i++) {
            func[i] = "IN";
            in_deg[i] = 0;
        }

        for (; i <= n + m; i++) {
            cin >> func[i] >> k;

            handle_status(i);
            in_deg[i] = k;
            for (int j = 1; j <= k; j++) {
                cin >> str;

                int u = get_index();
                add_edge(u, i);
            }
        }
        can = toposort();

        cin >> s;
        for (i = 1; i <= s; i++) {
            int j;
            for (j = 1; j <= m; j++) {
                cin >> status[j];
            }

            if (can) {
                solve();

                for (; j <= n + m; j++) {
                    output[i][j] = status[j];
                    handle_status(j);
                }
            }
        }
        for (i = 1; i <= s; i++) {
            cin >> num;

            for (int j = 0; j < num; j++) {
                cin >> id;

                if (can) {
                    printf("%d ", output[i][id + m]);
                }
            }
            if (can) {
                printf("\n");
            }
        }
        if (!can) {
            printf("LOOP\n");
        }
    }

    return 0;
}