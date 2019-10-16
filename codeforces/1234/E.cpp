#include <bits/stdc++.h>
using namespace std;

#define int long long


template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class T> ostream &operator<<(ostream &os, set<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class K, class X> ostream &operator<<(ostream& os, map<K,X> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)



// segtree
const int N = 2e5 + 1;
int n;
int t[2 * N];

void build() {
    for(int i = n - 1; i > 0; --i) {
        t[i] = t[i<<1] + t[i<<1|1];
    }
}

void modify(int pos, int value) {
    for(t[pos += n] = value; pos > 1; pos >>= 1) {
        t[pos >> 1] = t[pos] + t[pos ^ 1];
    }   
}

int query(int l, int r) {  // sum on interval [l, r) for char c
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, np;
    cin >> m >> np;
    vector<int> x(np, 0);
    map<int, vector<int> > pos;
    for(int i = 0; i < np; i++) {
        cin >> x[i];
        pos[x[i]].push_back(i);
    }
    n = np - 1;
    for(int i = 0; i < n; i++) {
        t[n + i] = 1;
    }
    // t[i] = abs(x[i+1] - x[i]) i = 0, 1, 2 ... n
    build();
    for(int i = 2; i < m; i++) {
        for(int x : pos[i]) {
            
        }
    }
    return 0;
}
