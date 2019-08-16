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

void solve(int cs, string n) {
    int k = n.length();
    vector<char> a(k), b(k);
    for(int i = k - 1; i >= 0; i--) {
        if(n[i] != '4') {
            a[i] = n[i];
            b[i] = '0';
        }
        else {
            a[i] = '1';
            b[i] = '3';
        }
    }
    cout << "Case #" << cs << ": ";
    int i = 0;
    while(i < k && a[i] == '0')
        i++;
    if(i == k)
        cout << 0;
    while(i < k) {
        cout << a[i++];
    }
    cout << " ";
    i = 0;
    while(i < k && b[i] == '0')
        i++;
    if(i == k)
        cout << 0;
    while(i < k)
        cout << b[i++];
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string s;
        cin >> s;
        solve(i + 1, s);
    }
    return 0;
}
