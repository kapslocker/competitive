#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    bool visit[n + 1] = {0};
    vector<int> arr(n);
    for(int i = 0; i < k; i++){
        cin >> arr[i];
        if(i >= 2){
            if(arr[i - 2] < arr[i - 1] && arr[i] < arr[i - 2]){
                cout << -1;
                return 0;
            }
        }
        visit[arr[i]] = 1;
    }
    vector<int> temp;
    int x, y, z, a, b;
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            temp.push_back(i);
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());
    if(k == 1){
        x = 0;
    }
    else{
        x = arr[k - 2];
    }
    y = arr[k - 1];
    if(temp.size() == 0){
        for(int i = 0; i < k; i++){
            cout << arr[i] << " ";
        }
        return 0;

    }
    z = temp[0];
    if(temp.size() == 1){
        if(x < y && x > z ){
            cout << "-1";
            return 0;
        }
        else{
            for(int i = 0; i < k; i++){
                cout << arr[i] << " ";
            }
            cout << temp[0];
            return 0;
        }
    }
    a = temp[1];
    if(temp.size() == 2){
        if(z < x){
            cout << "-1";
            return 0;
        }
        else{
            for(int i = 0; i < k; i++){
                cout << arr[i] << " ";
            }
            cout << z << " " << a << endl;
            return 0;

        }
    }
    b = temp[2];

    // check for less than three elements
    if(x < y && z < x){
        cout << "-1";
        return 0;
    }
    if(x < y){
        if(z < x){
            cout << "-1";
            return 0;
        }
        else if(x < z && z < y){
            for(int i = 0; i < k; i++){
                cout << arr[i] << " ";
            }
            for(auto t : temp){
                cout << t << " ";
            }
            return 0;
        }
        else{
            // z > y
            if(a > y){
                for(int i = 0; i < k; i++){
                    cout << arr[i] << " ";
                }
                for(auto t : temp){
                    cout << t << " ";
                }
                return 0;
            }
            else{
                if(b < y){
                    if(b < x){
                        cout << "-1";
                        return 0;
                    }
                    temp.erase(temp.begin() + 2);
                    for(int i = 0; i < k; i++){
                        cout << arr[i] << " ";
                    }
                    cout << b << " ";
                    for(auto t : temp){
                        cout << t << " ";
                    }
                    return 0;
                }
                else{
                    temp.erase(temp.begin());
                    for(int i = 0; i < k; i++){
                        cout << arr[i] << " ";
                    }
                    for(auto t : temp){
                        cout << t << " ";
                    }
                    cout << z << endl;
                    return 0;
                }
            }
        }
    }
    else{
        if(z < y){
            for(auto t : temp){
                cout << t << " ";
            }
            return 0;
        }
        else{
            if(a > y){
                for(auto t : temp){
                    cout << t << " ";
                }
                return 0;
            }
            else{
                if(b < y){
                    temp.erase(temp.begin() + 2);
                    cout << b << " ";
                    for(auto t : temp){
                        cout << t << " ";
                    }
                    return 0;
                }
                else{
                    temp.erase(temp.begin());
                    for(auto t : temp){
                        cout << t << " ";
                    }
                    cout << z << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
