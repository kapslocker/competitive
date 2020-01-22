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

int dfs(map<int, vector<int> > &graph, vector<bool> &visited, int u) {
    int depth = 0;
    visited[u] = true;
    for(int &v: graph[u]) {
        if(visited[v])
            continue;
        depth = max(depth, dfs(graph, visited, v));
    }
    return 1 + depth;
}

vector<bool> taken;
void dfs2(map<int, vector<int> > &graph, int u, int d) {
    taken[u] = true;
    if(d == 0)
        return;
    for(int &v : graph[u]) {
        if(taken[v])
            continue;
        dfs2(graph, v, d - 1);
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    taken.resize(n + 1, 0);
    map<int, vector<int> > graph;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    set<int> ans;
    for(int u = 1; u <= n; u++) {
        dfs2(graph, u, k / 2);
        for(int i = 1; i <= n; i++) {
            if(taken[i])
                ans.insert(i);
        }
        taken.resize(n + 1, 0);
    }
    cout << n - ans.size() << endl;
    return 0;
}
