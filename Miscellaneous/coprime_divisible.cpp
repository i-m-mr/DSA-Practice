// You have been given numbers ‘x’ and ‘y’. Print all the numbers between 1 and x which follow the below criteria
// 1. Should be co-prime with x
// 2. Should be divisible by ‘y’

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public : 
    int gcd(int x, int y) {
        if(y == 0) return x;
        return gcd(y, x%y);
    }
    void solve(int x, int y) {
        for(int l=x; l<y; l++) {
            if(gcd(x, l) == 1 && y%l == 0) 
                cout << l << " ";
        }
    }
};

int main(){
    
    int x, y;
    cin >> x >> y;

    Solution obj;
    obj.solve(x, y);

    return 0;
}  