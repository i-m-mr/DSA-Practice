// Given a string str, return true if the str can be palindrome after deleting at most one character from it.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public : 
    bool checkPal(string s) {
        int start = 0, end = s.length()-1;
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    bool checkPalindromeAfterRemove(string s) {
        for(int i=0; i<s.length(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            // cout << left << " " << right << endl;
            string word = left + right;
            if(checkPal(word)) return true;
        }
        return false;
   }
};

int main(){
    string s;
    cin >> s;

    Solution obj;
    bool ans = obj.checkPalindromeAfterRemove(s);
    
    if(ans == true) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;    

    return 0;
}  