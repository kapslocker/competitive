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


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n;
    int maxn = 150002;
    vector<int> count(maxn, 0), is_possible(maxn, 0);
    for(int i = 0; i < n; i++) {
        cin >> t;
        count[t]++;
    }
    for(int i = 0; i < maxn; i++) {
        int prev = max(1, i-1), next = min(i+1, maxn-1);
        if(count[i] == 1) {
            if(!is_possible[prev])
                is_possible[prev] = 1;
            else if(!is_possible[i]) {
                is_possible[i] = 1;
            }
            else {
                is_possible[next] = 1;
            }
        }
        if(count[i] == 2) {
            if(!is_possible[prev]) {
                is_possible[prev] = 1;
                is_possible[prev+1] = 1;
            }
            else if(!is_possible[i]) {
                is_possible[i] = 1;
                is_possible[next] = 1;
            }
            else {
                is_possible[next] = 1;
            }
            
        }
        if(count[i] >= 3) {
            is_possible[prev] = 1;
            is_possible[i] = 1;
            is_possible[next] = 1;
        }

    }
    int ans = 0;
    for(int i = 0; i < maxn; i++){
        if(is_possible[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
