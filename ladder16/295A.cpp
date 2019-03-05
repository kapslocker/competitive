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
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...);            }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> arr(n + 1), check(m + 2, 0), change(n+2, 0);
    vector<pair<pair<int, int>, int> > updates(m + 1);
    for(int i = 0; i < n; i++) {
        cin >> arr[i + 1];
    }
    for(int i = 0; i < m; i++) {
        cin >> updates[i+1].first.first >> updates[i+1].first.second >>
            updates[i+1].second;
    }
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        check[x]++;
        check[y+1]--;
    }
    int cumulative = 0;
    for(int i = 1; i <= m; i++) {
        cumulative = cumulative + check[i];
        updates[i].second *= cumulative;
    }
    for(int i = 1; i <= m; i++) {
        int l = updates[i].first.first, r = updates[i].first.second;
        change[l] += updates[i].second;
        change[r+1] -= updates[i].second;
    }
    cumulative = 0;
    for(int i = 1; i <= n; i++) {
        cumulative += change[i];
        arr[i] += cumulative;
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i+1] << " ";
    }
    cout << endl;
    return 0;
}
