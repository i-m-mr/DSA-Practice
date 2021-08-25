#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, int k) {
        if(k == s3.length() && i == s1.length() && j == s2.length())
            return true;
        
        cout << "i - " << i << " " << "j - "<<j<< " "<<"k - " << k << endl;
        
        if(s1[i] == s3[k] && s2[j] == s3[k]) {
            return solve(s1, s2, s3, i+1, j, k+1) || solve(s1, s2, s3, i, j+1, k+1);
        }
        else if(i < s1.length() && s1[i] == s3[k]) {
            return solve(s1, s2, s3, i+1, j, k+1);
        }
        else if(j < s2.length()  && s2[j] == s3[k]) {
            return solve(s1, s2, s3, i, j+1, k+1);
        }
        else {
            return false;
        }
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m=s2.length(), l = s3.length();
        
        if(n+m != l) {
            return false;
        }
        
        return solve(s1, s2, s3, 0 , 0 , 0);
    }
};

int main () {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cout << s1.length() << " " << s2.length() <<" " << s3.length() << endl; 

        Solution ob;

        bool ans = ob.isInterleave(s1, s2, s3);
        cout << ans << endl;
    }

    return 0;
}