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

const int mod = 1e9 + 7;

int modpow(int n, int p) {
    if(p == 1)
        return n;
    if(p == 0)
        return 1;
    if(p % 2 == 0) {
        return modpow((n * n) % mod, p / 2);
    }
    return (n * modpow((n * n) % mod, p / 2)) % mod;
}


void dfs(map<int, vector<int> >&graph, vector<int> &sizes, vector<bool> &visited, int src, int s) {
    if(visited[s])
        return;
    if(s == src) {
        sizes.push_back(1);
    }
    else
        sizes.back()++;
    visited[s] = true;
    for(auto &v : graph[s]) {
        dfs(graph, sizes, visited, src, v);
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    map<int, vector<int> > graph;
    for(int i = 0; i < n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        if(x == 1)
            continue;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<int> sizes;
    for(int i = 0; i < n; i++) {
        dfs(graph, sizes, visited, i, i);
    }
    int m = sizes.size();
    int term1 = modpow(n, k), term2 = 0;
    for(int i = 0; i < m; i++) {
        term2 += modpow(sizes[i], k);
        term2 %= mod;
    }
    ans = term1 - term2;
    if(ans < 0)
        ans += mod;
    cout << ans << endl;
    return 0;
}
