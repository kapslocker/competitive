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


int rev(int s, vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        int idx = (s + i) % n;
        if(arr[idx] < arr[(idx + 1) % n]) {
            return false;
        }
    }
    return true;
}

int ahead(int s, vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        int idx = (s + i) % n;
        if(arr[idx] > arr[(idx + 1) % n]) {
            return false;
        }
    }
    // debug(s, arr);
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        bool found = false;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++) {
            if(ahead(i, arr) || rev(i, arr)) {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
