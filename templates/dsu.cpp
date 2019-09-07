#include <bits/stdc++.h>
using namespace std;

#define int long long

class dsu{
    int MAX;
public:
    vector<int> parent;
    vector<int> sz;
    dsu(int range) {
        MAX = range + 10;
        parent.resize(MAX, -1);
        sz.resize(MAX, 1ll);
    }
    int find(int x) {
        if(parent[x] == -1) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void join(int x, int y) {
        int r = find(x);
        int s = find(y);
        if(r != s) {
            parent[r] = s;
            sz[s] += sz[r];
        }
    }
};

int main() {
    int a = 1, b = 2;
    dsu d(10);
    int r = d.find(a), s = d.find(b);
    cout << r << " " << s << endl;
    d.join(a, b);
    cout << d.find(a) << " " << d.find(b) << endl;
}