#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    return  gcd(b, a%b);
}

int solve(int n) {
    int res = 0;
    for(int i=1; i<n; i++) {
        if(gcd(n, i) == 1) res++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int ans = solve(n);
    cout << "Resilt : " << ans;
    return 0;
}