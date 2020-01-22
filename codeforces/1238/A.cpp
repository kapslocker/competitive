#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, r;
        cin >> n >> r;
        set<int> st;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        vector<int> arr(st.begin(), st.end());
        n = arr.size();
        int ans = 0;
        for(int i = n - 1; i>= 0; i--) {
            arr[i] -= ans * r;
            if(arr[i] <= 0)
                break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
