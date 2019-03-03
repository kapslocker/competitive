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

const int MAXN = 4000;
set<int> primes;
vector<bool> mark(MAXN, 0);
void sieve() {
    for(int i = 2; i < MAXN; i++) {
        if(mark[i]) continue;
        primes.insert(i);
        for(int j = i * i; j < MAXN; j += i)
            mark[j] = true;
    }
}

void update(vector<int> &arr, unordered_map<int, int> &hmap) {
    int n = arr.size();
    int c1 = 0;
    for(auto &p : primes) {
        if(c1 == n)
            break;
        for(int i = 0; i < n; i++) {
            if(arr[i] >= p && arr[i] % p == 0) {
                hmap[p]++;
                while(arr[i] % p == 0)
                    arr[i] /= p;
            }
            if(primes.find(arr[i]) != primes.end()) {
                hmap[arr[i]]++;
                arr[i] = 1;
            }
            if(arr[i] == 1)
                c1++;
        }
    }
    if(c1 == n)
        return;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 1)
            hmap[arr[i]]++;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;
    sieve();
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int g = arr[0];
    for(int i = 1; i < n; i++) {
        g = gcd(g, arr[i]);
    }
    for(int i = 0; i < n; i++) {
        arr[i] /= g;
    }
    unordered_map<int, int> hmap;
    update(arr, hmap);
    for(auto &k : hmap) {
        ans = max(ans, k.second);
    }
    if(ans > 0)
        cout << n - ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
