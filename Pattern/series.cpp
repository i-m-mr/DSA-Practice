#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter a no b/w 1-10 : ";
    cin >> n;    // input

    double fact = 1;     // factorial
    double sum = 0;
    for(int i=1; i<=n; i++) {
        fact *= i;
        sum += (i / fact);
    }
    cout << sum << endl;     // print

    return 0;
}