#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int cz = arr[n - 1];
    bool ans[n] = {0};
    for(int i = 0; i < n - 1; i++){
        ans[i] = arr[i + 1] > arr[i] ? 1 : 0;
        if(arr[i])
            cz--;
    }
    if(cz)
        arr[n-1] = 1;
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
