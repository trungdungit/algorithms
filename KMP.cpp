#include <bits/stdc++.h>
using namespace std;

vector<int> naive_prefix(string s) {
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i - k + 1, k))
                pi[i] = k;
    return pi;
}

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int k = pi[i - 1] + 1;
        while (k && s.substr(0, k) != s.substr(i - k + 1, k))
            k--;
        pi[i] = k;
    }
    return pi;
}

vector<int> prefix_function1(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int KMP(string s, string t) {
    int n = s.size(), m = t.size();
    vector<int> pi = prefix_function(s);
    int ans = 0;
    int j = 0;

    for (int i = 0; i < m; i++) {
        while (j > 0 && t[i] != s[j])
            j = pi[j - 1];
        if (t[i] == s[j])
            j++;
        if (j == n)
            ans++;
    }
}