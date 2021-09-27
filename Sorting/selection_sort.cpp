#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int mn = i;
        for(int j=i; j<n; j++) {
            if(arr[mn] > arr[j]) {
                mn = j;
            }
        }
        swap(arr[i], arr[mn]);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    solve(arr, n);
    cout <<"After Sorting : " << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}