#include<bits/stdc++.h>
using namespace std;

void sieve(vector<bool> &isPrime, int n) {
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2; i*i<=n; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> isPrime(n+1, true);

    sieve(isPrime, n);
    
    cout << "prime no's int the range is : " << endl;
    for(int i=2; i<=n; i++) {
        if(isPrime[i]) cout << i << " ";
    }
    return 0;
}