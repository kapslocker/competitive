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

int check(int area, unordered_map<int, int> &count, vector<int> &sides) {
    for(int i = 0; i < sides.size(); i++) {
        if(area % sides[i]) {
            return false;
        }
        int a = sides[i], b = area / a;
        if(count[a] != count[b])
            return false;
        if(count[a] % 2 != 0)
            return false;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        vector<int> arr(4 *n);
        unordered_map<int, int> count;
        for(int i = 0; i < 4 * n; i++) {
            cin >> arr[i];
            count[arr[i]]++;
        }
        set<int> areas;
        bool found = false;
        for(int i = 0; i < 4 * n; i++) {
            for(int j = 0; j < i; j++) {
                int area = arr[i] * arr[j];
                if(check(area, count, arr)) {
                    cout << "YES" << endl;
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        if(!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
