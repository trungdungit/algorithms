#include <bits/stdc++.h>
using namespace std;

class MITM {
    int N; //40-100
    int n, x;
    vector<int> t;
    vector<int> A, B;
public:
    MITM() {
        t.assign(N, 0);
    }

    void tryX(int i, int sum) {
        if (sum > x) return;
        if (i > n/2) A.push_back(sum);
        else {
            tryX(i + 1, sum);
            tryX(i + 1, sum + t[i]);
        }
    }

    void tryY(int i, int sum) {
        if (sum > x) return;

        if (i > n) B.push_back(sum);
        else {
            tryY(i + 1, sum);
            tryY(i + 1, sum + t[i]);
        }
    }

    void mitm() {
        tryX(1, 0);
        tryY(n/2 + 1, 0);

        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());

        long long cnt = 0;
        for (int i = 0, j1 = 0, j2 = 0; i < A.size(); ++i) {
            int s = x - A[i];
            while (j1 < B.size() && B[j1] < s) ++j1;
            while (j2 < B.size() && B[j2] <= s) ++j2;
            cnt += j2 - j1;
        }
    }
};