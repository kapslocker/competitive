#include <iostream>

using namespace std;

const int N = 1e5;

int n;
int t[2 * N];

void build() {
    for(int i = n - 1; i >= 0; i--) {
        // t[i] = t[2*i] + t[2 *i + 1]
        t[i] = t[i<<1] + t[i<<1|1];
    }
}

void modify(int pos, int value) {
    pos = pos + n;
    t[pos] = value;
    while(pos > 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1];
        pos >>= 1;
    }
}

int query(int l, int r) {
    // [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r>>= 1) {
        if(l&1)
            res += t[l++];
        if(r&1)
            res += t[--r];
    }
    return res;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", t + n + i);
    build();
    modify(0, 1);
    printf("%d\n", query(3, 11));
    return 0;
}
