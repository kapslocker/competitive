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

vector<int> color;

void dfs(unordered_map<int, vector<int> > &graph, set<int> &vertices, vector<vector<int> > &dp, string &str, int s, bool &iscycle) {
    if(color[s] == 2)
        return;
    color[s] = 1;
    for(auto &v : graph[s]) {
        if(color[v] == 1) {
            iscycle = true;
            return;
        }
        dfs(graph, vertices, dp, str, v, iscycle);
    }
    for(int j = 0; j < 26; j++) {
        int maxval = 0;
        for(auto &v : graph[s]) {
            maxval = max(maxval, dp[v][j]);
        }
        dp[s][j] = maxval;
    }
    dp[s][str[s] - 'a']++;
    vertices.erase(s);
    color[s] = 2;
}


int32_t main() {
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    string key;
    cin >> key;
    unordered_map<int, vector<int> > graph;
    set<int> vertices;
    color.resize(n);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
    }
    for(int i = 0; i < n; i++) {
        vertices.insert(vertices.end(), i);
    }
    vector<vector<int> > dp(n, vector<int>(26, -1));
    while(!vertices.empty()) {
        int s = *vertices.begin();
        bool iscycle = false;
        dfs(graph, vertices, dp, key, s, iscycle);
        for(int j = 0; j < 26; j++)
            ans = max(ans, dp[s][j]);
        if(iscycle) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
