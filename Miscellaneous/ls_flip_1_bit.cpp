#include<bits/stdc++.h>
using namespace std;

int solve(int n, int nums[]) {
    int count = 0, ans = 0, j= 0;
    
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) count++;
        while(count > 1) {
            if(nums[j] == 0) count--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int nums[n];
    for(int i=0; i<n; i++) cin >> nums[i];

    int ans = solve(n, nums);    
    cout << "Ans : " << ans << endl;

    return 0;
}