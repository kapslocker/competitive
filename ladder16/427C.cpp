#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

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

void dfs(unordered_map<int, vector<int>> &graph, vector<bool> &visited,
         stack<int> &order, int u) {
  if (visited[u])
    return;
  visited[u] = true;
  for (int v : graph[u]) {
    dfs(graph, visited, order, v);
  }
  order.push(u);
}

void assign(unordered_map<int, vector<int>> &rev_graph,
            unordered_map<int, vector<int>> &component,
            vector<bool> &is_assigned, int u, int root) {
  if (is_assigned[u])
    return;
  is_assigned[u] = true;
  component[root].push_back(u);
  for (int v : rev_graph[u])
    assign(rev_graph, component, is_assigned, v, root);
}

void scc(unordered_map<int, vector<int>> &graph,
         unordered_map<int, vector<int>> &rev_graph,
         unordered_map<int, vector<int>> &component, int n) {
  vector<bool> visited(n + 1);
  stack<int> order;
  for (int i = 0; i <= n; i++) {
    dfs(graph, visited, order, i);
  }
  for (int i = 0; i <= n; i++) {
    visited[i] = !visited[i];
  }
  while (!order.empty()) {
    int v = order.top();
    order.pop();
    assign(rev_graph, component, visited, v, v);
  }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> cost(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> cost[i + 1];
    }
    unordered_map<int, vector<int> > graph, rev_graph, component;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
    long long int mincost = 0, num_mincost = 1;
    scc(graph, rev_graph, component, n);
    for(auto &p : component) {
        int minv = INT_MAX, count_minv = 0;
        for(int v : p.second) {
            minv = min(minv, cost[v]);
        }
        for(int v : p.second) {
            if(cost[v] == minv) {
                count_minv++;
            }
        }
        mincost += minv;
        num_mincost = (num_mincost * count_minv) % mod;
    }
    cout << mincost << " " << num_mincost << endl;
    return 0;
}
