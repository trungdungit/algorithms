#include <bits/stdc++.h>
using namespace std;

#define OPERATOR(x, y) min(x, y)

class SegmentTree {
    static const inline int INF = 1e9 + 7;
    static const inline int maxN = 1e5 + 7;
    int n, q;
    int a[maxN];
    int st[4 * maxN];

public:
    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        int m = (l + r)/2;
        build(2 * id, l, m);
        build(2* id + 1, m+1, r);

        st[id] = OPERATOR(st[2*id], st[2*id + 1]);
    }

    void update(int id, int l, int r, int i, int val) {
        if (l > i || r < i) return;

        if (l == r) {
            st[id] = val;
            return;
        }

        int m = (l + r)/2;
        update(2 * id, l, m, i, val);
        update(2 * id + 1, m + 1, r, i, val);

        st[id] = OPERATOR(st[2 * id], st[2 * id + 1]);
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) return;
        if (u <= l && r <= v) {
            st[id] = val;
            return;
        }

        int m = (l + r)/2;
        update(2 * id, l, m, u, v, val);
        update(2 * id + 1, m + 1, r, u, v, val);

        st[id] = OPERATOR(st[2 * id], st[2 * id + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (l >  v || r <  u) return INF;

        if (l >= u && r <= v) return st[id];

        int m = (l + r)/2;
        int get1 = get(2 * id, l, m, u, v);
        int get2 = get(2 * id + 1, m + 1, r, u, v);

        return OPERATOR(get1, get2);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return INF;
        if (u <= l && r <= v) return st[id];
        int m = (l + r) / 2;

        int get1 = get(2 * id, l, m, u, v);
        int get2 = get(2 * id + 1, m + 1, r, u, v);

        return OPERATOR(get1, get2);
    }
};