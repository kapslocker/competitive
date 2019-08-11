#include <bits/stdc++.h>
using namespace std;

void printAmbi1(vector<int> &arr, int curr, int pos){
    for(int i = pos; i < arr.size(); i++){
        if(arr[i] == 1){
            printf("%d ", curr);
            curr++;
        }
        else{
            if(arr[i - 1] == 1){
                int u = curr;
                for(int j = 0; j < arr[i]; j++){
                    printf("%d ", u);
                    curr++;
                }
            }
            else{
                int u = curr - arr[i - 1] + 1;
                for(int j = 0; j < arr[i]; j++){
                    printf("%d ", u);
                    curr++;
                }
                // printAmbi1(arr, curr, i);
            }
        }
    }
}

void printAmbi2(vector<int> &arr, int curr, int pos){
    for(int i = pos; i < arr.size(); i++){
        if(arr[i] == 1){
            printf("%d ", curr);
            curr++;
        }
        else{
            if(arr[i - 1] == 1){
                int u = curr ;
                for(int j = 0; j < arr[i]; j++){
                    printf("%d ", u);
                    curr++;
                }
            }
            else{
                int u = curr - arr[i - 1] + 1;
                for(int j = 0; j < arr[i] - 1; j++){
                    printf("%d ", u);
                    curr++;
                }
                printf("%d ", u + 1);
                curr++;
            }
        }
    }
}

int main(){
    int h, s = 0;
    cin >> h;
    vector<int> arr(h + 1);
    for(int i = 0; i <= h; i++){
        scanf("%d", &(arr[i]));
        s += arr[i];
    }
    for(int i = 0; i < h; i++){
        if(arr[i] != 1){
            if(arr[i + 1] != 1){
                printf("%s\n", "ambiguous");
                printAmbi1(arr, 0, 0);
                printf("\n");
                printAmbi2(arr, 0, 0);
                return 0;
            }
        }
    }
    cout << "perfect" << endl;
    return 0;
}
