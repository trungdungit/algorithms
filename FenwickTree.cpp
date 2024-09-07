#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    static const inline int N = 1e9 + 7;
    int bit[N];

public:
    int get(int p) {
        int idx = 0, ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }

    void update(int u, int val) {
        int idx = u;
        while (idx <= N) {
            bit[idx] += val;
            idx += (idx & (-idx));
        }
    }
};

class FenwickTree2D {
    static const inline int N = 1e9 + 7;
    static const inline int M = 1e9 + 7;
    int bit[N][M];

public:
    void update(int u, int v, int x ){
        for(int i = u; i <= N; i += i&(-i)){
            for(int j = v; j <= M; j += j&(-j))
                bit[i][j]+=x;
        }
    }
    int get(int u, int v) {
        int sum = 0;
        for(int i = u; i > 0; i -= i&(-i)){
            for(int j = v; j > 0; j -= j&(-j))
                sum += bit[i][j];
        }
        return sum;
    }
};