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


int dfs(map<int, vector<int> > &tree, int v, vector<bool> &visited) {
    int ans = 0;
    visited[v] = true;
    for(int& u : tree[v]) {
        if(visited[u])
            continue;
        int x = dfs(tree, u, visited);
        ans = max(ans, x);
    }
    return 1 + ans;
}

int check(map<int, vector<int> > &tree, int s) {
    int largest_size = 0, n = tree.size(), center;
    vector<bool> visited(n + 1, false);
    visited[s] = true;
    for(int &v : tree[s]) {
        int sz = dfs(tree, v, visited);
        if(sz > largest_size) {
            largest_size = sz;
            center = v;
        }
    }
    if(2 * largest_size <= n)
        return -1;
    return center;
}

int centroid_tree(map<int, vector<int> > &tree) {
    int current = 1, found = false;
    while(!found) {
        int resp = check(tree, current);
        if(resp == -1)
            return current;
        current = resp;
    }
}

bool fill(map<int, vector<int> > &tree, vector<char> &colors, int v, char up) {
    if(colors[v] != '$')
        return true;
    up++;
    if(up < 'A' || up > 'Z')
        return false;
    colors[v] = up;
    for(auto &u : tree[v]) {
        if(!fill(tree, colors, u, up))
            return false;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<int, vector<int> > tree;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int root = centroid_tree(tree);
    vector<char> colors(n + 1, '$');
    bool possible = fill(tree, colors, root, 'A' - 1);
    if(!possible) {
        cout << "Impossible!\n";
        return 0;
    }
    for(int i = 1; i <= n; i++)
        cout << colors[i] << " ";
    cout << endl;
    return 0;
}
