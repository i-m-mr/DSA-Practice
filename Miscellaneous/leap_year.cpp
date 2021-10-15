// Write Java Program to find out whether the year is a leap year
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public : 
    void leapYear(int year) {
        if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                cout << year << " is a leap year.";
            else
                cout << year << " is not a leap year.";
        }
        else
            cout << year << " is a leap year.";
    }
    else
        cout << year << " is not a leap year.";
    }
};

int main(){
    int year;
    cin >> year;

    Solution obj;
    obj.leapYear(year); 

    return 0;
}  