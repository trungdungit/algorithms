#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int st[1000000];
    int top = 0;

    void push(int x) {
        ++top;
        st[top] = x;
    }

    void pop() {
        assert(top);
        --top;
    }

    int peek() {
        return st[top];
    }
};

class HashTable {
    vector<pair<int, int>> h[1000000];

    int getHash(int key) {
        return key % 1000000;
    }
public:
    void insert(int key, int value) {
        int hkey = getHash(key);
        for (auto p : h[hkey]) {
            if (p.first == key) {
                return;
            }
        }
        h[hkey].emplace_back(key, value);
    }

    int find(int key) {
        int hkey = getHash(key);
        for(auto p : h[hkey]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return 0;
    }
};