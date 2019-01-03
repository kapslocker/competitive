#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

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

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T>
struct tree_t {
  class edge { public: int to; int from; T cost; };

  using vi = vector<int>; using vvi = vector<vi>;

  int n; vector<edge> edges; vector<vector<int>> g;

  tree_t(int n): n(n), g(n) {}

  void add(int from, int to, T cost = 1) {
    assert(0 <= from < n and 0 <= to < n);
    g[to].push_back(edges.size());  g[from].push_back(edges.size());
    edges.push_back({from, to, cost});
  }

  vi order; vi pe; vi pv; vi sz; vi depth; vi pos; vi end; vi root; 
  vector<T> dist;

  void init_dfs() {
    order.clear(); root = vi(n, -1); pe = vi(n, -1); pv = vi(n, -1);
    pos = vi(n, -1); end = vi(n, -1); sz = vi(n, 0); depth = vi(n, -1);
    dist.clear(); dist = vector<T>(n);
  }

  void do_dfs(int v) {
    pos[v] = order.size(); order.push_back(v); sz[v] = 1;
    for(int id: g[v]) { if(id == pe[v]) continue;
      auto &e = edges[id]; int to = e.to ^ e.from ^ v; pe[to] = id; pv[to] = v;
      depth[to] = depth[v] + 1; dist[to] = dist[v] + e.cost;
      root[to] = root[v]; do_dfs(to); sz[v] += sz[to];
    }
    end[v] = order.size() - 1;
  }

  void do_dfs_from(int v) {
    pe[v] = -1; pv[v] = -1; depth[v] = 0; root[v] = v; 
    dist[v] = T(); do_dfs(v);
  }

  int dfs(int v) { init_dfs(); do_dfs_from(v); assert(order.size() == n); 
    return v; 
  }

  vvi pr; int h;

  void build_lca() {
    assert(not pv.empty()); int max_depth = 0;
    for(int i = 0; i < n; ++i) { max_depth = max(max_depth, depth[i]); }
    int h = 1; while((1 << h) <= max_depth) { ++h; }
    pr = vvi(n, vi(h));
    for(int i = 0; i < n; ++i) { pr[i][0] = pv[i]; }
    for(int j = 1; j < h; ++j) { for(int i = 0; i < n; ++i) {
        pr[i][j] = (pr[i][j-1] == -1) ? -1 : pr[pr[i][j-1]][j-1];
    } }
  }

  inline bool anc(int x, int y) { return pos[x] <= pos[y] and end[y] <= end[x]; }

  inline int lca(int x, int y) {
    assert(not pr.empty()); assert(not pv.empty());
    if(anc(x, y)) return x; if(anc(y, x)) return y;
    for(int j = h - 1; j >= 0; --j) {
      if(pr[x][j] != -1 and not anc(pr[x][j], y)) { x = pr[x][j]; }
    }
    return pv[x];
  }

  vi head; vi length_down;

  inline void build_hld(int v) { dfs(v);
    for(int i = 0; i < n; ++i) { int best = -1, bid = 0;
      for(int j = 0; j < (int)g[i].size(); ++j) {
        int id = g[i][j];
        if(id == pe[i]) continue;
        int to = edges[id].to ^ edges[id].from ^ i;
        if(sz[to] > best) { best = sz[to]; bid = j; }
      } swap(g[i][bid], g[i][0]);
    }
    dfs(v); build_lca(); head.resize(n); length_down.resize(n);
    for(int i = 0; i < n; ++i) { head[i] = i; length_down[i] = 1; }
    for(int i = 0; i < n - 1; ++i) {
      int x = order[i]; int y = order[i + 1];
      if(x == pv[y]) { head[y] = head[x]; }
    }
    for(int i = n; i > 0; --i) { int x = order[i];
      if(x != head[x]) { length_down[pv[x]] = length_down[x] + 1;
      }
    }
  }

  void apply_on_path(int x, int y, bool with_lca, function<void(int,int,bool)> f) {
    // f(x, y, up): up -- whether this part of the path goes up
    int z = lca(x, y);
    {
      int v = x;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) { f(pos[z] + 1, pos[v], true); break; }
        f(pos[head[v]], pos[v], true);
        v = pv[head[v]];
      }
    }
    if (with_lca) {
      f(pos[z], pos[z], false);
    }
    {
      int v = y;
      int cnt_visited = 0;
      while (v != z) {
        if (depth[head[v]] <= depth[z]) { f(pos[z] + 1, pos[v], false); break; }
        visited[cnt_visited++] = v;
        v = pv[head[v]];
      }
      for (int at = cnt_visited - 1; at >= 0; at--) {
        v = visited[at];
        f(pos[head[v]], pos[v], false);
      }
    }
  }

};

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  tree_t<int> g(n);
  for(int i = 0; i < n-1; ++i) {
    int x, y; cin >> x >> y;
    g.add(x, y, 1);
  }
  g.build_hld(0);
  cout << g.order << endl;
}
