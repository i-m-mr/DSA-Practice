#include<bits/stdc++.h>
using namespace std;

int main(){
    float x1,x2,x3;
    float y1,y2,y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

     int a = x1 * (y2 - y3)
            + x2 * (y3 - y1)
            + x3 * (y1 - y2);
 
    if (a == 0)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}