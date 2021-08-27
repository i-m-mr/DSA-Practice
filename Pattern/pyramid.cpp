#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n = 5;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=(n-i);j++){
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }


int main() {

    int n = 5;
    int i = 1;
    while(i <= n) {
        int j = 1;
        while(j <= (n-i)) {
            cout << " ";
            j++;
        }
        int k = 1;
        while(k <= i) {
            cout << "*";
            k++; 
        }
        i++;
    }
    return 0;
}