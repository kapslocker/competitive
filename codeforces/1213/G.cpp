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

class dsu{
    int MAX;
public:
    vector<int> parent;
    vector<int> sz;
    dsu(int range) {
        MAX = range + 10;
        parent.resize(MAX, -1);
        sz.resize(MAX, 1);
    }
    int find(int x) {
        if(parent[x] == -1) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void join(int x, int y) {
        int r = find(x);
        int s = find(y);
        if(r != s) {
            parent[r] = s;
            sz[r] += sz[s];
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, pair<int, int> > > tree;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree.push_back({w, {u, v}});
    }
    map<int, pair<int, int> > queries;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        queries[x].first = i;
        queries[x].second = 0;
    }
    dsu d(2e5);
    int it = 0;
    for(auto &[q, i] : queries) {
        while(it < tree.size()) {
            int u = tree[it].second.first, v = tree[it].second.second, w = tree[it].first;
            if(w > q)
                break;
            int a = d.find(u), b = d.find(v), sa = d.sz[a], sb = d.sz[b];
            d.join(a, b);
            ans = ans + ((sa + sb) * (sa + sb - 1)) / 2 - (sa * (sa - 1)) / 2 - (sb * (sb - 1)) / 2;
            i.second = ans;
            it++;
        }
    }
    for(auto &[a,b] : tree) {
        debug(b.first, b.second, d.find(b.first), d.find(b.second));
    }
    vector<int> out(m);
    for(auto &[a, b] : queries)
        out[b.first] = b.second;
    for(int i = 0; i < m; i++)
        cout << out[i] << " ";
    cout << endl;
    return 0;
}
