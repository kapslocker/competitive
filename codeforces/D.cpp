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


bool check0(string &str) {
    int len = str.length();
    int mid = (len) / 2;
    for(int i = 0; i < mid; i++) {
        if(str[i] != str[0])
            return false;
    }
    return true;
}

inline bool checkpalin(string &str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev == str;
}

bool check1(string &str) {
    for(int i = 1; i < str.length() - 1; i++) {
        string a = str.substr(0, i), b = str.substr(i);
        string c = b + a;
        if(checkpalin(c) && (c != str))
            return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    if(check0(str)) {
        cout << "Impossible\n";
        return 0;
    }
    if(check1(str)) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
    return 0;
}
