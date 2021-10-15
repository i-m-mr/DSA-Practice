// Print those numbers ‘I’ between x and y which are the same when vertically inverted
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public : 
    bool checkPal(int n) {
        int temp = 0, num = n;
        while(num > 0) {
            temp = temp*10 + num%10;
            num /= 10;
        }
        return n == temp;
    }
};

int main(){
    int x, y;
    cin >> x >> y;

    Solution obj;

    for(int i=x; i<=y; i++) {
        bool ans = obj.checkPal(i);
        if(ans == true) cout << i << " ";
    }  

    return 0;
}  