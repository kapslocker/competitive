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
    int n;
    cin >> n;
    vector<int> arr(n);
    string s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> s;
    int i = -1, j = 0;
    while(i < n - 1) {
        // move to first zero.
        while(j < n - 1 && s[j] != '0')
            j++;
        if(j == n - 1) {
            cout << "YES" << endl;
            return 0;
        }
        // i + 1 to j should contain i + 1 to j only.
        for(int t = i+1; t <= j; t++) {
            if(arr[t] < i + 2 || arr[t] > j + 1) {
                cout << "NO" << endl;
                return false;
            }
        }
        i = j;
        j = i + 1;
        // 
    } 
    cout << "YES" << endl;
    return 0;
}
