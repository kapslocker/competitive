#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isprime(int n) {
    if(n == 2 || n == 3)
        return true;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    for(int i = 5; i <= sqrt(n); i+=6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int32_t main() {
    int n, it = 1;
    cin >> n;
    set<pair<int, int> > edges;
    for(int i = 1; i <= n - 1; i++) {
        edges.insert({i, i + 1});
    }
    edges.insert({n, 1});
    while(!isprime(edges.size())) {
        edges.insert({it, it + 2});
        if(isprime(edges.size()))
            break;
        edges.insert({it + 1, it + 3});
        it = it + 4;
    }
    cout << edges.size() << endl;
    for(auto &[a, b] : edges) {
        cout << a << " " << b << endl;
    }
    return 0;
}