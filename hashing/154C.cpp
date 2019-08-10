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

const int p = 47, mod = (1ll << 63) + 1;

int modpow(int x, int n) {
    if(n == 0)
        return 1;
    if(n % 2 == 0) {
        return modpow((x * x) % mod, n / 2);
    }
    return (x * modpow((x * x) % mod, n / 2)) % mod;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> graph(n + 1, 0);
    map<int, int> values;
    vector<pair<int, int> > edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u] += modpow(p, v);
        graph[v] += modpow(p, u);
        graph[u] %= mod;
        graph[v] %= mod;
        edges.push_back({u, v});
    }
    int count = 0;
    for(auto &[u, v] : edges) {
        // check edges
        int a = graph[u], b = graph[v], c = modpow(p, u), d = modpow(p, v);
        if((a + c) % mod == (b + d) % mod)
            count++;
    }
    // check away neighbors, zero degrees
    for(int i = 1; i <= n; i++) {
        values[graph[i]]++;
    }
    for(auto &[v, c] : values) {
        count += (c * (c - 1)) / 2;
    }
    cout << count << endl;
    return 0;
}
