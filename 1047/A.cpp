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

const int MAXN = 4000, N = 15000001;
vector<int> primes;
vector<int> cnt(N, 0);
vector<bool> mark(MAXN, 0);
vector<int> small(N);

void sieve() {
    for(int i = 2; i < MAXN; i++) {
        if(mark[i]) continue;
        primes.push_back(i);
        for(int j = i * i; j < MAXN; j += i)
            mark[j] = true;
    }
    iota(small.begin(), small.end(), 0);
    for(int &p : primes) {
        for(int j = p * p; j < N; j += p) {
            small[j] = min(small[j], p);
        }
    }
}

void update(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int x = arr[i], temp;
        while(x > 1) {
            temp = small[x];
            x = x / temp;
            if(temp != small[x])
                cnt[temp]++;
        }
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
    update(arr);
    for(auto &k : cnt) {
        ans = max(ans, k);
    }
    if(ans > 0)
        cout << n - ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
