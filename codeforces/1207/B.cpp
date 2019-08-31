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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > A(n + 2, vector<int>(m + 2, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    vector<pair<int, int> > ans;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(A[i][j] == 0)
                continue;
            else if(A[i-1][j-1] && A[i-1][j] && A[i][j-1]) {
                ans.push_back({i-1, j-1});
            }
            else if(A[i][j+1] && A[i+1][j] && A[i+1][j+1]) {
                ans.push_back({i, j});
            }
            else if(A[i][j-1] && A[i+1][j] && A[i+1][j-1]) {
                ans.push_back({i, j-1});
            }
            else if(A[i-1][j] && A[i-1][j+1] && A[i][j+1]) {
                ans.push_back({i-1, j});
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
