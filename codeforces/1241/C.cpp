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

int x, y, a, b, k;

const int MAX = 2e5 + 2;

vector<int> temp(MAX), arr(MAX);

bool check(vector<int> &p, int m) {
    for(int i = 1; i <= m; i++)
        temp[i] = 0;
    int ptr = 0, contri = 0;
    int l = lcm(a,b);
    for(int i = l; i <= m; i += l) {
        temp[i] = p[ptr++];
        contri += (x + y) * temp[i];
    }
    if(x < y) {
        swap(x, y);
        swap(a, b);
    }
    for(int i = a; i <= m; i+= a) {
        if(temp[i])
            continue;
        temp[i] = p[ptr++];
        contri += x * temp[i];
    }
    for(int i = b; i <= m; i+=b) {
        if(temp[i])
            continue;
        temp[i] = p[ptr++];
        contri += y * temp[i];
    }
    if(contri >= k) {
        return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        arr.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] /= 100;
        }
        cin >> x >> a >> y >> b >> k;
        sort(arr.begin(), arr.end(), greater<int>());
        int low = 1, mid = 1, high = n + 1;
        while(low < high - 2) {
            mid = (low + high) / 2;
            if(check(arr, mid)) {
                high = mid + 1;
            }
            else {
                low = mid + 1;
            }
        }
        bool found = false;
        for(int i = low; i < high; i++) {
            if(check(arr, i)) {
                cout << i << endl;
                found = true;
                break;
            }
        }
        if(!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}
