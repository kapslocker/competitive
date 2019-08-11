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


vector<int> wsum, bsum;
unordered_map<int, vector<int> > smap;

void dfs(unordered_map<int, vector<int> > &graph, vector<int> &w, vector<int> &b, vector<int> &visited, int s, int seg) {
    if(visited[s])
        return;
    wsum[seg] += w[s];
    bsum[seg] += b[s];
    smap[seg].push_back(s);
    visited[s] = true;
    for(auto &v : graph[s])
        dfs(graph, w, b, visited, v, seg);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, W, x, y;
    cin >> n >> m >> W;
    vector<int> ws(n), bs(n), visited(n, false);
    for(int i = 0; i < n; i++) { cin >> ws[i]; }
    for(int i = 0; i < n; i++) { cin >> bs[i]; }
    unordered_map<int, vector<int> > graph;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    wsum.resize(n); bsum.resize(n);
    int seg = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            seg++;
        dfs(graph, ws, bs, visited, i, seg);
    }
    // maximize bsum, minimize wsum
    vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            for(auto &v : smap[i]) {
                if(ws[v] <= w)
                    dp[i][w] = max(dp[i][w], bs[v] + dp[i - 1][w - ws[v]]);
            }
            if(wsum[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], bsum[i - 1] + dp[i - 1][w - wsum[i - 1]]);
            }
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}
