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

vector<int> parent(101, -1);

int find(int x) {
    if(parent[x] == -1)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void join(int x, int y) {
    int pa = find(x), pb = find(y);
    if(pa != pb)
        parent[pa] = pb;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > points(n);
    map<pair<int, int>, int> code;
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        code[points[i]] = i;
    }
    int additional = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(points[i].first == points[j].first || points[i].second == points[j].second) {
                join(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int pa = find(i), pb = find(j);
            if(pa != pb) {
                additional++;
                join(pa, pb);
            }
        }
    }
    cout << additional << endl;
    return 0;
}
