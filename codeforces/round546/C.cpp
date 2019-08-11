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

vector<vector<int> > A, B;

bool solvek(int k, int n, int m) {
    map<int, int> count;
    for(int i = 0; i < n; i++) {
        int j = k - i;
        if(j < 0 || j >= m)
            continue;
        count[A[i][j]]++;
    }
    for(int i = 0; i < n; i++) {
        int j = k - i;
        if(j < 0 || j >= m)
            continue;
        if(count[B[i][j]] == 0)
            return false;
        count[B[i][j]]--;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    A.resize(n, vector<int>(m));
    B.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }
    for(int k = 0; k <= n + m; k++) {
        if(!solvek(k, n, m)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
