#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k, profit = 0;
    cin >> n >> k;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    for(int i = n - k; i < n; i++){
        profit += v[i];
        ans.push_back(v[i]);
    }
    cout << profit << '\n';
    for(int i = 0; i < k; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
