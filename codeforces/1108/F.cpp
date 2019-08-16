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

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int MAX = 200001;
vector<int> parent(MAX, -1);

int find(int x) {
    if(parent[x] == -1)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void join(int x, int y) {
    int r = find(x);
    int s = find(y);
    if(r != s)
        parent[r] = s;
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b, w, ans = 0;
    cin >> n >> m;
    map<int, set<pair<int, int> > > hmap;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        hmap[w].insert({a, b});
    }
    for(auto &p: hmap) {
        w = p.first;
        set<pair<int, int> > seg;
        int done = 0, k = 0;
        for(auto &t: p.second) {
            a = t.first; b = t.second;
            int pa = find(a), pb = find(b);
            if(pa != pb) {
                k++;
            }
        }
        for(auto &t : p.second) {
            a = t.first; b = t.second;
            int pa = find(a), pb = find(b);
            if(pa != pb) {
                join(pa, pb);
                done++;
            }
        }
        ans += k - done;
    }
    cout << ans << endl;
    return 0;
}
