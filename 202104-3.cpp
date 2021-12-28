#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int N, t_def, t_max, t_min, n, t;
string h;

struct P{
    P() {}
    P(string _send, string _recv, string _type, int _ip, int _time) {
        send = _send;
        recv = _recv;
        type = _type;
        ip = _ip;
        time = _time;
    }

    string send, recv, type;
    int ip, time;
};
P p;

struct Addr{
    int status, time;
    string user;
};
Addr addr[maxn];

void init(int i) {
    addr[i].status = 0;
    addr[i].user = "";
    addr[i].time = 0;
}

void timeout() {
    for (int i = 1; i <= N; i++) {
        if (addr[i].status == 1 && addr[i].time <= t) {
            init(i);
        } else if (addr[i].status == 2 && addr[i].time <= t) {
            addr[i].status = 3;
            addr[i].time = 0;
        }
    }
}

void output(P p) {
    printf("%s %s %s %d %d\n", p.send.c_str(), p.recv.c_str(), p.type.c_str(), p.ip, p.time);
}

int check_user() {
    for (int i = 1; i <= N; i++) {
        if (addr[i].user == p.send) return i;
    }

    for (int i = 1; i <= N; i++) {
        if (addr[i].status == 0) return i;
    }

    for (int i = 1; i <= N; i++) {
        if (addr[i].status == 3) return i;
    }
    return -1;
}

int set_time() {
    if (p.time == 0) return t + t_def;

    int length = p.time - t;
    if (length >= t_min && length <= t_max) return p.time;

    if (length < t_min) return t + t_min;
    return t + t_max;
}

void discover() {
    int ip = check_user();
    if (ip == -1) return;

    addr[ip].status = 1;
    addr[ip].user = p.send;
    addr[ip].time = set_time();

    P q(h, p.send, "OFR", ip, addr[ip].time);
    output(q);
}

void find_user() {
    for (int i = 1; i <= N; i++) {
        if (addr[i].user == p.send) {
            if (addr[i].status == 1) {
                init(i);
            }
        }
    }
}

void request() {
    if (p.recv != h) {
        find_user();
        return;
    }

    if (p.ip < 1 || p.ip > N || addr[p.ip].user != p.send) {
        P q(h, p.send, "NAK", p.ip, 0);
        output(q);
        return;
    }

    addr[p.ip].status = 2;
    addr[p.ip].user = p.send;
    addr[p.ip].time = set_time();

    P q(h, p.send, "ACK", p.ip, addr[p.ip].time);
    output(q);
}

int main() {
    cin >> N >> t_def >> t_max >> t_min >> h >> n;

    for (int i = 0; i < maxn; i++) {
        init(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> t >> p.send >> p.recv >> p.type >> p.ip >> p.time;

        timeout();

        if (p.recv == h || p.recv == "*") {
            if (p.type == "DIS" || p.type == "REQ") {
                if (p.recv == "*" && p.type == "DIS") {
                    discover();
                } else if (p.recv == h && p.type == "REQ") {
                    request();
                }
            }
        } else {
            if (p.type == "REQ") {
                request();
            }
        }
    }

    return 0;
}