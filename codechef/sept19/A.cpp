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

int fibd(int n) {
    n = n % 60;
    vector<int> arr(60, 0);
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < 60; i++) {
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= 10;
    }
    return arr[n];
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int n = 1;
        while(n <= x) {
            if(2 * n > x)
                break;
            n = 2 * n;
        }
        cout << fibd(n-1) << endl;
    }
    return 0;
}
