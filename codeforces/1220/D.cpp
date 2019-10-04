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
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, int> count;
    vector<int> mark(n, 0);
    for(int i = 0; i < n; i++) {
        int x = arr[i], c = 0;
        while(x && x % 2 == 0) {
            c++;
            x >>=1;
        }
        count[c]++;
    }
    int maxval = 0, pow;
    for(auto &x : count) {
        if(x.second > maxval) {
            maxval = x.second;
            pow = x.first;
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int x = 1 << pow;
        if(arr[i] % x != 0 || arr[i] % (2 * x) == 0) {
            ans.push_back(arr[i]);
        }
    }
    cout << ans.size() << endl;
    for(int x : ans) {
        cout << x << " "; 
    }
    cout << endl;
    return 0;
}
