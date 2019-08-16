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

map<int, vector<int> > graph;

int choose(int n) {
    return (n * (n - 1));
}

bool lucky(int x) {
    while(x > 0) {
        int t = x % 10;
        if(t != 4 && t != 7)
            return false;
        x = x / 10;
    }
    return true;
}
void dfs(vector<bool> &visited, vector<int> &sizes, int src, int u) {
    if(visited[u])
        return;
    visited[u] = true;
    if(u != src)
        sizes.back()++;
    else
        sizes.push_back(1);
    for(auto &v : graph[u]) {
        dfs(visited, sizes, src, v);
    }
}

void evalsizes(vector<int> &sizes, int n) {
    vector<bool> visited(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        dfs(visited, sizes, i, i);
    }
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u,v, w;
        cin >> u >> v >> w;
        if(!lucky(w)) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    vector<int> sizes;
    evalsizes(sizes, n);
    int k = sizes.size(), total = 0, tot_comb = 0;
    for(int i = 0; i < k; i++) {
        total += sizes[i];
        tot_comb += choose(sizes[i]);
    }
    int ans = 0;
    for(int i = 0; i < k; i++) {
        int contribution = choose(total - sizes[i]);
        ans += sizes[i] * contribution;
    }
    cout << ans << endl;
    return 0;
}
