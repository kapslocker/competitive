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


unordered_map<int, int> idx;
bool compare(int a, int b) {
    return idx[a] < idx[b];
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, u;
    cin >> n;
    unordered_map<int, vector<int> > graph;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> seq(n);
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
        idx[seq[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }
    vector<int> bfs;
    queue<int> q;
    q.push(1);
    vector<int> visited(n + 1, 0);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        bfs.push_back(u);
        visited[u] = 1;
        for(auto &v : graph[u]) {
            if(!visited[v])
                q.push(v);
        }
    }
    for(int i = 0; i < n; i++) {
        if(seq[i] != bfs[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
