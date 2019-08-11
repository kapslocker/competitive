#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, ans = 0, temp;
        cin >> n;
        for(int bit = 0; bit < 9; bit++) {
            vector<int> a, b;
            for(int i = 1; i <= n; i++) {
                if( (i >> bit) & 1)
                    a.push_back(i);
                else
                    b.push_back(i);
            }
            if(a.size() == 0 || b.size() == 0)
                continue;
            cout << a.size() << " " << b.size() << " ";
            for(int i : a)  cout << i << " ";
            for(int j : b)  cout << j << " ";
            cout << endl;
            cin >> temp;
            ans = max(ans, temp);
        }
        cout << -1 << " " << ans << endl;
    }
    return 0;
}
