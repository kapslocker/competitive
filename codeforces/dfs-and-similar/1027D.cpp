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


map<int, int> mincost;
vector<int> cost;
void dfs(int u, map<int, vector<int> > &graph, vector<int> &visited, int s) {
    if(visited[u])
        return;
    visited[u] = s;
    if(s >= visited.size()) {
        if(mincost[s] == 0)
            mincost[s] = cost[u];
        else
            mincost[s] = min(mincost[s], cost[u]);
    }
    for(int v: graph[u]) {
        dfs(v, graph, visited, s);
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cost.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    map<int, vector<int> > graph;
    vector<int> incoming(n+1, 0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        graph[x].push_back(i);
        if(x != i)
            incoming[i]++;
    }
    vector<int> visited(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(!incoming[i]) {
            dfs(i, graph, visited, i);
        }
    }
    debug(graph);
    debug(incoming);
    debug(visited);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, graph, visited, n + i);
        }
    }
    debug(visited);
    int ans = 0;
    set<int> seen;
    for(int i = 1; i <= n; i++) {
        if(seen.find(visited[i]) != seen.end())
            continue;
        seen.insert(visited[i]);
        if(visited[i] <= n) {
            ans += visited[i];
        }
        else {
            ans += mincost[visited[i]];
        }
    }
    cout << ans << endl;
    return 0;
}
