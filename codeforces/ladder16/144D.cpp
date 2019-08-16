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

map<int, vector<pair<int, int> > > graph;
vector<bool> visited;
void dijkstra(vector<int> &dist, int s) {
    set<pair<int, int> > vertices;
    int n = graph.size();
    dist[s] = 0;
    for(int i = 1; i <= n; i++) {
        vertices.insert({dist[i], i});
    }
    while(!vertices.empty()) {
        pair<int, int> pi = *vertices.begin();
        vertices.erase(vertices.begin());
        int curr = pi.first, u = pi.second;
        for(auto &[d, v] : graph[u]) {
            if(curr + d < dist[v]) {
                vertices.erase(vertices.find({dist[v], v}));
                dist[v] = curr + d;
                vertices.insert({dist[v], v});
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s, l;
    cin >> n >> m >> s;
    set<pair<pair<int, int>, int> > edges;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
        edges.insert({{u, v}, w});
    }
    cin >> l;
    vector<int> dist(n + 1, INT_MAX);
    dist[0] = 0;
    dijkstra(dist, s);
    debug(dist);
    int ans = 0;
    for(int u = 1; u <= n; u++) {
        if(dist[u] == l)
            ans++;
    }
    for(auto edge : edges) {
        int u = edge.first.first, v = edge.first.second, w = edge.second;
        int a = min(dist[u], dist[v]), b = max(dist[u], dist[v]);
        if(a >= l && b >= l)
            continue;
        double dval = b + (w - b + a) / 2.0;
        debug(u, v, dval);
        if(dval < l || dval == a || dval == b)
            continue;
        if(dval == l) {ans++; continue;}
        if(dist[u] < l)
            ans++;
        if(dist[v] < l)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
