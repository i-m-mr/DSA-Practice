// Given a string str, return true if the str can be palindrome after deleting at most one character from it.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public : 
    int gcd(int num1, int num2) {
        if(num2 == 0) return num1;
        return gcd(num2, num1%num2);
    }
};

int main(){
    int num1, num2;
    cin >> num1 >> num2;

    Solution obj;
    int gcd = obj.gcd(num1, num2);
    int ans = (num1*num2) / gcd;
    
    cout << "LCM of " << num1 << " and " << num2 << " : " << ans << endl;  

    return 0;
}  