#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int n;
int tree[2  * N];

void build() {
    for(int i = n - 1; i > 0; i--) {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }
}

void modify(int p, int value) {
    // set t[n+p] = value
    t[n + p] = value;
    for(;p > 1; p >>= 1) {
        t[p >> 1] = t[p] + t[p ^ 1];
    }
}

int query(int l, int r) {
    // sum on interval [l, r)
    int ans = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1)   ans += t[l++];
        if(r & 1)   ans += t[--r];
    }
    return ans;
}

int main() {

    return 0;
}
