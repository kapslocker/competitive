#include <bits/stdc++.h>
using namespace std;

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
template<class K, class X> ostream &operator<<(ostream& os, unordered_map<K,X> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

map<int, bool> visited1;
int count_problem(unordered_map<int, vector<int> > &tree, map<pair<int, int>, int> &type_map, vector<int> &counts, int root) {
    int count = 0;
    visited1[root] = true;
    for(int v : tree[root]) {
        if(visited1[v])
            continue;
        if(type_map[{root, v}] == 2) {
            count++;
        }
        count += count_problem(tree, type_map, counts, v);
    }
    counts[root] = count;
    return count;
}

map<int, bool> visited2;
void dfs(unordered_map<int, vector<int> > &tree, map<pair<int, int>, int> &type_map, vector<int> &counts, vector<int> &req, int u) {
    if(counts[u] == 0)
        return;
    visited2[u] = true;
    for(int v : tree[u]) {
        if(visited2[v])
            continue;
        if(counts[v] > 0) {
            dfs(tree, type_map, counts, req, v);
        }
        else if(type_map[{u, v}] == 2) {
            req.push_back(v);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y, t;
    cin >> n;
    unordered_map<int, vector<int> > tree;
    map<pair<int, int>, int> type_map;
    for(int i = 0; i < n - 1; i++) {
        cin >> x >> y >> t;
        tree[x].push_back(y);
        tree[y].push_back(x);
        type_map[{x, y}] = t;
    }
    vector<int> counts(n + 1), req;
    count_problem(tree, type_map, counts, 1);
    dfs(tree, type_map, counts, req, 1);
    cout << req.size() << endl;
    for(int v : req)
        cout << v << " ";
    cout << endl;
    return 0;
}
