#include <iostream>
#include <vector>

using namespace std;

#define int long long

int32_t main() {
    string str;
    cin >> str;
    vector<int> arr;
    int curr = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'o') {
            arr.push_back(curr);
            curr = 0;
        }
        else
            curr++;
    }
    arr.push_back(curr);
    int n = arr.size(), total = 0, pre = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i])
            arr[i]--;
    }
    for(int i : arr)
        total += i;
    for(int i = 0; i < n; i++) {
        pre = pre + arr[i];
        ans = ans + pre * (total - pre); 
    }
    cout << ans << endl;
}