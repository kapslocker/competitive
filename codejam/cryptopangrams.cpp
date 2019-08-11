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

vector<int> primes;

int MAXN = 1e5 + 1;

void sieve() {
    vector<bool> visited(MAXN + 1, false);
    for(int i = 2; i * i <= MAXN; i++) {
        if(visited[i])
            continue;
        for(int j = i * i; j <= MAXN; j += i) {
            visited[j] = true;
        }
    }
    for(int i = 2; i <= MAXN; i++) {
        if(!visited[i])
            primes.push_back(i);
    }
}

void print(int cs, vector<int> &message) {
    set<int> chars;
    for(int i : message)
        chars.insert(i);
    vector<int> alph = vector<int>(chars.begin(), chars.end());
    map<int, int> hmap;
    for(int i = 0; i < alph.size(); i++) {
        hmap[alph[i]] = i;
    }
    cout << "Case #" << cs << ": ";
    for(int i = 0; i < message.size(); i++) {
        cout << (char)('A' + (char)hmap[message[i]]);
    }
    cout << endl;
}

void solve(int cs, int n, vector<int> &arr) {
    int p, q, l = arr.size();
    int m = primes.size();
    vector<int> mess(arr.size() + 1);
    for(int i = 0; i < m; i++) {
        if(arr[0] % primes[i] == 0) {
            p = primes[i];
            q = arr[0] / p;
            break;
        }
    }
    if(arr.size() == 1) {
        mess[0] = p;
        mess[1] = q;
        print(cs, mess);
        return;
    }
    int idx = 1;
    while(idx < l && arr[idx] == arr[idx - 1]) {
        idx++;
    }
    if(idx == l) {
        // alternate p, q
        for(int i = 0; i < l + 1; i++) {
            if(i % 2)   mess[i] = p;
            else    mess[i] = q;
        }
        print(cs, mess);
        return;
    }
    if(arr[idx] % p == 0) {
        mess[idx] = p;
        // for(int i = idx; i >= 0; i -= 2) {
        //     mess[i] = p;
        // }
        // for(int i = idx - 1; i >= 0; i -= 2) {
        //     mess[i] = q;
        // }
    }
    else if(arr[idx] % q == 0) {
        mess[idx] = q;
        // for(int i = idx; i >= 0; i -= 2) {
        //     mess[i] = q;
        // }
        // for(int i = idx - 1; i >= 0; i -= 2) {
        //     mess[i] = p;
        // }
    }
    for(int i = idx - 1; i >= 0; i--) {
        mess[i] = arr[i] / mess[i + 1];
    }
    int prev = mess[idx];
    for(int i = idx; i < l; i++) {
        mess[i+1] = arr[i] / prev;
        prev = mess[i+1];
    }
    print(cs, mess);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    sieve();
    for(int i = 0; i < t; i++) {
        int n, l;
        cin >> n >> l;
        vector<int> arr(l);
        for(int j = 0; j < l; j++) {
            cin >> arr[j];
        }
        solve(i + 1, n, arr);
    }
    return 0;
}
