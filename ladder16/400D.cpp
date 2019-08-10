#include <set>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <limits.h>
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
template<class K, class X> ostream &operator<<(ostream& os, unordered_map<K,X> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

vector<pair<int, pair<int, int> > > edges;

bool dfs(set<int> &complete_tags, unordered_map<int, vector<pair<int, int> > > &graph,
        vector<int> &tag, vector<bool> &visited, int u) {
    if(visited[u])
        return true;
    int type = tag[u];
    if(complete_tags.find(type) != complete_tags.end()) {
        return false;
    }
    visited[u] = true;
    for(auto &[v, w] : graph[u]) {
        if(tag[v] != type) {
            edges.push_back({type, {tag[v], w}});
            continue;
        }
        if(w > 0)
            continue;
        dfs(complete_tags, graph, tag, visited, v);
    }
    complete_tags.insert(tag[u]);
    return true;
}

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(k + 1), tag(n + 1, 0);
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    unordered_map<int, vector<pair<int , int> > > graph;
    int it = 1, curr = 1, u, v, w;
    while(curr <= k) {
        tag[it++] = curr;
        c[curr]--;
        if(!c[curr])
            curr++;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    set<int> complete_tags;
    vector<bool> visited(n + 1, false);
    for(int i = 1; i <= n; i++) {
        bool found = dfs(complete_tags, graph, tag, visited, i);
        if(!found) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    unordered_map<int, vector<pair<int, int> > > kgraph;
    vector<vector<int> > dp(k + 1, vector<int> (k + 1, INT_MAX));
    for(int i = 0; i < edges.size(); i++) {
        kgraph[edges[i].first].push_back(edges[i].second);
        dp[edges[i].first][edges[i].second.first] = edges[i].second.second;
        dp[edges[i].second.first][edges[i].first] = edges[i].second.second;
    }
    for(int i = 1; i <= k; i++) {
        dp[i][i] = 0;
    }
    for(int x = 1; x <= k; x++) {
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= k; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            if(dp[i][j] < INT_MAX)
                cout << dp[i][j] << " ";
            else
                cout << -1 << " ";
        }
        cout << endl;
    }
    return 0;
}