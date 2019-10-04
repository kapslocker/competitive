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

const int N = 1e5 + 1;

vector<int> parent(N, -1);

void unionize(int x, int y) {
    if(parent[x] == -1) {
        parent[x] = y;
        return;
    }
    if(parent[x] == parent[y])
        return;
    parent[x] = y;
}

int find(int x) {
    if(parent[x] == -1)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, vector<int> > graph;
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        unionize(u, v);
    }
    for(int i = 1; i <= n; i++) {
        find(i);
    }
    set<int> diff;
    for(int i = 1; i <= n; i++) {
        if(parent[i] == -1) {
            diff.insert(i);
        }
        else
            diff.insert(parent[i]);
    }
    debug(diff);
    cout << diff.size() - 1 << endl;
    vector<int> d(diff.begin(), diff.end());
    for(int i = 0; i < d.size() - 1; i++) {
        cout << d[i] << " " << d[i+1] << endl;
    }
    return 0;
}
