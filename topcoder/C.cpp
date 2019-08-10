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


bool check(vector<double> T, int n, int target, double x) {
    int lval = n * target;
    double rval = x;
    for(int i = 2; i <= n; i++) {
        double price = x * T[i];
        price = price * 100;
        price = round(price) / 100.0;
        rval += price;
    }
    if(rval >= lval)
        return true;
    return false;
}

double getPrice(int n, vector<int> C, int target) {
    vector<double> T(n + 1, 1.0);
    for(int i = 2; i <= n; i++) {
        T[i] = (T[i - 1] * (100.0 + C[i - 2])) / 100.0;
    }
    double low = 0.0, high = 1000000.0, mid;
    while(abs(high - low) > 1e-3) {
        mid = (low + high) / 2.0;
        if(check(T, n, target, mid) == false) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    low = low * 100;
    low = round(low) / 100;
    return low;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> C(n - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> C[i];
    int target;
    cin >> target;
    cout << getPrice(n, C, target) << endl;
    return 0;
}
